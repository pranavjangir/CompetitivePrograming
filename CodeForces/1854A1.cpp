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
typedef pair<ll,ll> pll;
ll n, a[30];
void prints(vector<pll> &ans) {
    cout << ans.size() << endl;
    for (auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}
void solve_neg(vector<pll> &ans) {
    for (ll i = n - 1; i >= 1; --i) {
        if (a[i] > a[i + 1]) {
            ans.push_back(make_pair(i, i + 1));
            a[i] += a[i + 1];
        }
    }
    prints(ans);
}


void solve_pos(vector<pll> &ans) {
    for (ll i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            ans.push_back(make_pair(i, i - 1));
            a[i] += a[i - 1];
        }
    }
    prints(ans);
}
void solve() {
    cin >> n;
    bool allneg = true;
    for (ll i = 1 ; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0 ) {
            allneg = false;
        }
    }
    vector<pll> ans;
    if (allneg) {
        solve_neg(ans); return;
    }
    int maxm = 0;
    int maxm_idx = -1;
    for (ll i = 1; i<=n;++i) {
        if (a[i] > maxm) {
            maxm = a[i];
            maxm_idx = i;
        }
    }
    for (ll i =1;i<=5;++i) {
        ans.push_back(make_pair(maxm_idx, maxm_idx));
        a[maxm_idx] += a[maxm_idx];
    }
    for (ll i = 1; i<=n;++i) {
        if (i == maxm_idx) continue;
        if (a[i] < 0) {
            ans.push_back(make_pair(i, maxm_idx));
            a[i] += a[maxm_idx];
            assert(a[i] >= 0);
        }
    }
    solve_pos(ans);
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}