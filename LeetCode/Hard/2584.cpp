#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        divs.resize(nums.size());
        ll n = nums.size();
        map<ll, ll> occ;
        for (ll i = 0; i < n; ++i) {
            occ[nums[i]] = i;
            for (ll j = 1; j*j <= nums[i]; ++j) {
                if (nums[i]%j == 0) {
                    divs[i].push_back(j);
                    divs[i].push_back(nums[i] / j);
                }
            }
        }
        vector< ll > a(n, 0);
        a[n - 1] = n - 1;
        map<ll, ll> mp;
        mp[a[n - 1]] = n-1;
        for (ll i = n - 2; i >=0 ; --i) {
            ll maxm = i;
            for (auto j : divs[i]) {
                maxm = max(maxm, mp[j]);
            }
            a[i] = maxm;
            if (mp[nums[i]] == 0) mp[nums[i]] = i;
        }
        for (ll i = 0; i < n;++i) {
            for (auto j : divs[i]) {
                if (occ.find(j) != occ.end()) {
                    ll id = occ[j];
                    a[id] = max(a[id], i);
                }
            }
        }
        ll cur = 0;
        for (ll i = 0; i < n; ++i) {
            cur = max(cur, a[i]);
            if (cur == i) break;
        }
        return (cur == n-1 ? -1 : cur);
    }
private:
    vector< vector<ll> > divs;
};