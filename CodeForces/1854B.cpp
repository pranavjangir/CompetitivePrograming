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

constexpr int N = 1e5+5;
int n, a[N + N];

int main() {
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bitset<N + N> poss;
    poss.reset();
    poss[0] = 1;
    ll ans = 0;
    ll prfx = 0;
    for (ll i = 1; i <= n + n; ++i) {
        prfx += a[i];
        if (poss[0]) {
            ans = max(ans, prfx - i + 1);
        }
        if (poss.any()) {
            poss |= (poss << a[i]);
        }
        poss = poss >> 1;
    }
    cout << ans << endl;
    return 0;
}