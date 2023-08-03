#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int N = 200005;
constexpr int M = N;

vector<int> g[N];
int n, m;
int c[N];
int seen[N];
int cnt;

void dfs(int v) {
    seen[v] = cnt;
    for (auto nn : g[v]) {
        if (c[nn] != c[v] && !seen[nn]) {
            dfs(nn);
        } else if (c[nn] == c[v] && seen[nn] == seen[v]) { // same component and same color.
            cout << "Yes\n";
            exit(0);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1 ; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            ++cnt;
            dfs(i);
        }
    }
    cout << "No\n";
    return 0;
}