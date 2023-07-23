// Tenzing and his animal friends.
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int N = 105;
constexpr int M = N*N / 2;
constexpr ll inf = 1e18;

typedef pair<ll,ll> pll;
ll n, m;
vector< vector<pll> > adj;

void print_subset(const vector<ll>& S, const ll rpt, vector<pair<string, ll> >& out) {
    string subset = "";
    for (ll i = 0; i < n; ++i) subset += '0';
    for (auto u : S) subset[u - 1] = '1';
    out.push_back(make_pair(subset, rpt));
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (ll i = 1;i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector <ll> dist(n + 1, inf);
    vector<pll> par(n + 1);
    for (ll i = 1;i <= n; ++i) par[i] = make_pair(-1, -1);
    dist[1] = 0;
    priority_queue <pll, vector<pll>, greater<pll> > pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto e : adj[u]) {
            ll v = e.first;
            ll w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = make_pair(u, w);
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if (dist[n] == inf) {
        cout << "inf\n";
        return 0;
    }
    vector< pll > D;
    for (ll i = 1;i <= n; ++i) D.push_back(make_pair(dist[i], i));
    sort(D.begin(), D.end());
    // vector<ll> S; // Just 1 is present.
    // ll cur = 1;
    vector<pair<string, ll> > ans;
    string cur_subset = "";
    for (int i = 1; i <= n; ++i) cur_subset += '0';
    // cur_subset[n - 1] = '0';
    for (int i = 0; i < n; ++i) {
        cur_subset[D[i].second - 1] = '1';
        if (i < n - 1 && D[i].first != D[i+1].first) {
            ans.push_back(make_pair(cur_subset, D[i+1].first - D[i].first));
        }
        if (D[i + 1].second == n) break;
    }
    cout << dist[n] << " " << ans.size() << "\n";
    for (auto e : ans) cout << e.first << " " << e.second << "\n";
    return 0;
}