#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        // think stack.
        ll n = nums.size();
        vector< ll > dp(n + 1, 0);
        stack<ll> S;
        S.push(n - 1);
        ll ans = 0;
        for (ll i = n - 2; i >= 0; --i) {
            while (!S.empty() && nums[S.top()] < nums[i]) {
                dp[i] = max(dp[i] + 1, dp[S.top()]);
                S.pop();
            }
            ans = max(ans, dp[i]);
            S.push(i);
        }
        return ans;
    }
};