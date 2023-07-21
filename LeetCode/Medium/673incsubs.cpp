# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        nums.push_back(-2000000);
        // i > j
        ll n = nums.size() - 1;
        vector < vector<pll> > dp; // LIS, count
        dp.resize(nums.size());
        for (ll i = 0; i <= n; ++i) {
            for (ll j = 0; j <= n; ++j) {
                dp[i].push_back(make_pair(0, 0));
            }
        }
        for (ll j = 0; j < n; ++j) {
            dp[n][j] = make_pair(0, 1);
        }
        for (ll i = n - 1 ; i >= 0; --i) {
            for (ll j = i - 1 ; j >= 0; --j) {
                ll chose_cur = 1 + dp[i + 1][i].first;
                if (nums[i] <= nums[j]) {
                    chose_cur = -2000001;
                }
                ll wout_best = dp[i + 1][j].first;
                if (chose_cur > wout_best) {
                    dp[i][j] = make_pair(chose_cur, dp[i + 1][i].second);
                } else if (wout_best > chose_cur) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = make_pair(chose_cur, dp[i + 1][i].second + dp[i + 1][j].second);
                }
            }
        }
        ll cur_max = 0;
        ll cnt = 0;
        for (ll i = 0 ; i < n; ++i) {
            if (dp[i + 1][i].first > cur_max) {
                cur_max = dp[i + 1][i].first;
                cnt = dp[i + 1][i].second;
            } else if (dp[i + 1][i].first == cur_max) {
                cnt += dp[i + 1][i].second;
            }
        }
        return cnt;
    }
};