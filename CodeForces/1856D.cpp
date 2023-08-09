#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ask(ll l, ll r) {
    if (l == r) {
        return 0;
    }
    cout << "? " << l << " " << r << endl;
    ll x;
    cin >> x;
    if (x == -1) {
        assert(false);
    }
    return x;
}

void ans(ll a) {
    cout << "! " << a << endl;
}

ll go(ll x, ll y) {
    if (x == y) {
        return x;
    }
    ll mid = (x + y) >> 1;
    ll A = go(x, mid);
    ll B = go(mid + 1, y);
    ll with = ask(A, B);
    ll wout = ask(A+1, B);
    if (with == wout + B - A) {
        return A;
    } else return B;
}

void solve() {
    ll n;
    cin >> n;
    ans(go(1, n));
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}