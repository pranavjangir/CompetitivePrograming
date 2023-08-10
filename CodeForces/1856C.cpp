#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
typedef long long ll;
using namespace std;

ll t;
ll n, k;
ll a[2002];
ll dp[2002];
ll steps[2002];

void solve() {
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    dp[n] = a[n];
    steps[n] = 0;
    for (ll i = n - 1 ; i >= 1; i--) {
        if (dp[i + 1] + 1 > a[i]) {
            dp[i] = dp[i + 1] + 1;
            steps[i] = steps[i + 1] + (dp[i + 1] - a[i] + 1);
        } else {
            dp[i] = a[i];
            steps[i] = 0;
        }
    }
    ll ans = -1;
    for (ll i = n ; i >= 1; --i) {
        cout << i << " -- " << steps[i] << " " << dp[i] << "\n";
        if (steps[i] <= k) {
            ans = max(ans, dp[i]);
            // continue;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}