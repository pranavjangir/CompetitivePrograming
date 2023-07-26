#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll, ll> pll;
ll n, m;
vector< vector<pll> > g;

// Edge reverse.

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}