#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 100005;
constexpr int MOD = 998244353;
ll n;
ll a[N], b[N];
int saturated[N];
ll sz[N];
ll p[N];

ll find_parent(ll x) {
    if (p[x] == x) return x;
    return p[x] = find_parent(p[x]);
}

bool union_sets(ll x, ll y) {
    x = find_parent(x);
    y = find_parent(y);
    assert(x != y);
    sz[x] += sz[y];
    if (saturated[x] && saturated[y]) return false;
    saturated[x] |= saturated[y];
    p[y] = x;
    return true;
}

void solve() {
    cin >> n;
    vector<bool> seen(n + 1, false);
    for (ll i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> b[i];
        p[i] = i;
        sz[i] = 1;
        saturated[i] = 0;
    }
    for (ll i = 1;i <=n; ++i) {
        if (find_parent(a[i]) == find_parent(b[i])) {
            if (saturated[find_parent(a[i])]) {
                cout << "0\n";
                return;
            } else {
                saturated[find_parent(a[i])] = 1;
                if (a[i] == b[i]) {
                    saturated[find_parent(a[i])] = 2;
                }
            }
        } else {
            bool success = union_sets(a[i], b[i]);
            if (!success) {
                cout << "0\n";
                return;
            }
        }
    }
    // Find the size of each component.
    // If size = 1. ans *= n;
    // o/w ans *= 2;
    ll ans = 1;
    for (ll i = 1;i <= n; ++i) {
        ll parent = find_parent(i);
        if (seen[parent]) continue;
        seen[parent] = true;
        if (saturated[parent] > 1) {
            ans = (ans * n)%MOD;
        } else {
            ans = (ans * 2)%MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}