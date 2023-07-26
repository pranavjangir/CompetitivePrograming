#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100005;
constexpr int M = N;
constexpr int inf = 1e9;

typedef pair<int,int> pll;

int n, m;

vector<int> d[N];

void divs() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            d[j].push_back(i);
        }
    }
}
int a[N];

pll greatest_element(const set<pll>& S) {
    auto e = S.end();
    e--;
    return *e;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = inf;
    set<pll> S;
    vector<int> cnt(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        S.insert(make_pair(inf, i));
        cnt[i] = inf;
    }
    for (int i = n; i >= 1; --i) {
        int el = a[i];
        for (auto di : d[el]) {
            if (di > m) continue;
            // eject the current entry for di.
            // enter the updated one.
            S.erase(make_pair(cnt[di], di));
            cnt[di] = i;
            S.insert(make_pair(cnt[di], di));
        }
        auto e = greatest_element(S);
        if (e.first == inf) {
            continue;
        }
        ans = min(ans, a[e.first] - el);
    }
    ans = (ans == inf ? -1 : ans);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    divs();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}