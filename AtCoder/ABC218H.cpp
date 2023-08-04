#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int N = 200005;
constexpr int R = N;
ll n, r;
ll a[N];

int main() {
    cin >> n >> r;
    if (r > n - r) r = n - r;
    for (ll i = 1;  i < n; ++i) {
        cin >> a[i];
    }
    
    return 0;
}