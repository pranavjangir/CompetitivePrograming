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
constexpr int N = 1e6 + 10;
int n;
vector<int> g[N];

int pw[21];

void calc_pw() {
    pw[0] = 1;
    for (int i = 1; i < 21; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
}

vector<int> massage(const vector<int>& c) {
    unordered_map<int, int> cnt;
    for (int x : c) {
        ++cnt[x];
    }
    vector<int> res;
    for (auto [x, y] : cnt) {
        ll j = 1;
        while (j < y) {
            res.push_back(x * j);
            y -= j;
            j *= 2;
        }            
        res.push_back(x * y);
    }
    return std::move(res);
}

int sz[N];
bool seen[N];
vector<int> R;

template<int C = 1>
int best_sum_possible(int sum) {
    if (C <= sum) {
        return best_sum_possible<std::min(2 * C, N)>(sum);
    }
    std::bitset<C> B;
    B[0] = 1;
    for (const int x : R) {
        B |= B << x;
    }
    for (int i = sum; i >= 0; --i) {
        if (B[i]) {
            return i;
        }
    }
    return 0;
}

ll dfs(int v) {
    seen[v] = true;
    ll ans = 0;
    vector<int> c;
    int S = 0;
    sz[v] = 0;
    for (int u : g[v]) {
        if (seen[u]) continue;
        ans += dfs(u);
        sz[v] += sz[u];
        c.push_back(sz[u]);
        S += sz[u];
    }
    R = massage(c);
    int best_sum = best_sum_possible(S / 2);
    ans += (ll)best_sum * (S - best_sum);
    sz[v] += 1;
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        ll u;
        cin >> u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    cout << dfs(1) << endl;
    return 0;
}