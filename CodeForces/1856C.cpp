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

bool check(ll x) {
    for (ll i = n; i >= 1; --i) {
        ll stps = 0;
        bool ok = true;
        ll cur = x;
        for (ll j = i; j <= n; ++j) {
            if (j == n && a[j] < cur) {
                ok = false;
                break;
            }
            if (a[j] >= cur) {
                break;
            } else {
                stps += cur - a[j];
                cur--;
            }
        }
        if (!ok) {
            continue;
        }
        if (stps <= k) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    ll lo = 0;
    ll hi = 2e8+1;
    while (hi > lo) {
        ll mid = (hi + lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else hi = mid - 1;
    }
    cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}