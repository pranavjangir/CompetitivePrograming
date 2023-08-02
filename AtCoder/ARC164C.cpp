#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, a[200005], s[200005];
ll ans = 0;
ll cnt = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;
        if (x < y) {
            ans += y;
            a[i] = x - y;
            s[i] = 1;
        } else {
            ans += x;
            a[i] = y - x;
            s[i] = 0;
            cnt++;
        }
    }
    if (cnt%2 == 0) {
        cout << ans << "\n";
        return 0;
    }
    ll maxm = -2e10;
    for (int i = 1 ; i <= n; ++i) maxm = max(maxm, a[i]);
    ans += maxm;
    cout << ans << "\n";
    return 0;
}