#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
private:
ll mod = 1e9 + 7;
ll dp[(1LL << 14)][15];
ll n;
vector< vector<ll> > divs;
ll solve(ll b, ll id) {
    if (b == (1LL << n) - 1) {
        return 1;
    }
    if (dp[b][id] != -1) return dp[b][id];
    if (((1LL << id)&b) == 0) {
        return dp[b][id] = 0;
    }
    ll ans = 0;
    for (auto j : divs[id]) {
        if (((1LL << j)&b)  == 0) {
            ans = (ans + solve((b | (1LL << j)), j))%mod;
        }
    }
    return dp[b][id] = ans;
}
public:

    int specialPerm(vector<int>& nums) {
        n = nums.size();
        divs.resize(n);
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0 ; j < (1LL << 14); ++j) {
                dp[j][i] = -1;
            }
            for (ll j = 0 ; j < i; ++j) {
                if (nums[i]%nums[j] == 0 || nums[j]%nums[i] == 0) {
                    divs[i].push_back(j);
                    divs[j].push_back(i);
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; ++i) {
            ans = (ans + solve((1LL << i), i))%mod;
        }
        return ans;
    }
};