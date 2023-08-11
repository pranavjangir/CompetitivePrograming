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

constexpr ll inf = 1e16;

ll n, a[100005], dp[100005];

class SegTree{
private:
    vector<ll> tree;
    inline ll left(ll id) { return id << 1; }
    inline ll right(ll id) { return (id << 1) + 1; }
public:
    SegTree(ll n) {
        tree.resize(4 * n);
    }
    void build(ll id, ll l, ll r) {
        if (l == r) {
            tree[id] = dp[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(left(id), l, mid);
        build(right(id), mid + 1, r);
        tree[id] = min(tree[left(id)], tree[right(id)]);
    }
    void upd(ll id, ll l, ll r, ll pos) {
        if (l == r) {
            tree[id] = dp[l];
            return;
        }
        ll mid = (l + r) >> 1;
        if (pos <= mid) {
            upd(left(id), l, mid, pos);
        } else {
            upd(right(id), mid + 1, r, pos);
        }
        tree[id] = min(tree[left(id)], tree[right(id)]);
    }
    ll query(ll id, ll l, ll r, ll x, ll y) {
        if (l > y || r < x) {
            return inf;
        }
        if (l >= x && r <= y) {
            return tree[id];
        }
        ll mid = (l + r) >> 1;
        return min(query(left(id), l, mid, x, y), query(right(id), mid + 1, r, x, y));
    }
};

int main() {
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = inf;
    }
    dp[1] = 0;
    SegTree S(n);
    S.build(1, 1, n);
    ll rr = min(n, a[1] + 1);
    dp[rr] = min(dp[rr], a[1]);
    S.upd(1, 1, n, rr);
    for (ll i = 2; i <= n; ++i) {
        ll R = min(i + a[i], n);
        ll yo = S.query(1, 1, n, i, n);
        dp[R] = min(dp[R], yo + a[i]);
        S.upd(1, 1, n, R);
    }
    ll ans = a[1];
    ll prfx = a[1];
    for (ll i = 2; i <= n; ++i) {
        prfx += a[i];
        ll min_cost = S.query(1, 1, n, i, n);
        ans = max(ans, prfx - min_cost);
    }
    cout << ans << endl;
    return 0;
}