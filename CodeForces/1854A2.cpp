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

ll t;
ll n, a[22], pos, neg;

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
    vector<pll> ans;
    cin >> n;
    pos = 0;
    neg = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            neg += 1;
        } else if (a[i] > 0) {
            pos += 1;
        }
    }
    if (pos == 0) {
        solve_neg(ans);
        return;
    } else if (neg == 0) {
        solve_pos(ans);
        return;
    }
    if (pos <= neg && pos <= 7) { // Make everything negative.
        ll id = -1;
        ll minm = 0;
        for (ll i = 1 ; i <= n; ++i) {
            if (a[i] < minm) {
                minm = a[i];
                id = i;
            }
        }
        for (ll i = 1; i <= 5; ++i) {
            ans.push_back(make_pair(id, id));
            a[id] += a[id];
        }
        for (ll i = 1; i <= n; ++i) {
            if (i == id) continue;
            if (a[i] > 0) {
                ans.push_back(make_pair(i, id));
                a[i] += a[id];
                assert(a[i] <= 0);
            }
        }
        solve_neg(ans);
    } else if (neg <= pos && neg <= 7) { // Make everything positive.
        ll id = -1;
        ll maxm = 0;
        for (ll i = 1 ; i <= n; ++i) {
            if (a[i] > maxm) {
                maxm = a[i];
                id = i;
            }
        }
        for (ll i = 1; i <= 5; ++i) {
            ans.push_back(make_pair(id, id));
            a[id] += a[id];
        }
        for (ll i = 1; i <= n; ++i) {
            if (i == id) continue;
            if (a[i] < 0) {
                ans.push_back(make_pair(i, id));
                a[i] += a[id];
                assert(a[i] >= 0);
            }
        }
        solve_pos(ans);
    } else {
        // pos > 7 && neg > 7
        // Skip the 5 steps required to make something maximum.
        // Switch over to the already maxm side.
        // This takes atmost 12 operations.
        ll id = -1;
        ll maxm = 0;
        for (ll i = 1 ; i <= n; ++i) {
            if (abs(a[i]) > maxm) {
                maxm = abs(a[i]);
                id = i;
            }
        }
        if (a[id] > 0) {
            for (ll i = 1; i <= n; ++i) {
                if (i == id) continue;
                if (a[i] < 0) {
                    ans.push_back(make_pair(i, id));
                    a[i] += a[id];
                    assert(a[i] >= 0);
                }
            }
            solve_pos(ans);
            return;
        } else {
            for (ll i = 1; i <= n; ++i) {
                if (i == id) continue;
                if (a[i] > 0) {
                    ans.push_back(make_pair(i, id));
                    a[i] += a[id];
                    assert(a[i] <= 0);
                }
            }
            solve_neg(ans);
            return;
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}