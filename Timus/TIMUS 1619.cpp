#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ld fac[30005];
void init()
{
        fac[0] = 1;
        for(ll i=1;i<=20002;i++) fac[i] = fac[i-1] * i;
}
ld C(ll x, ll y)
{
        if(x < y) return 1.0;
        ld ret = fac[x];
        ret = ret / fac[y];
        ret = ret / fac[x-y];
        return ret;
}
ld cats(ll x)
{
        ld ret = C(x+x,x);
        ret /= (ld)(1.0 + 1.0*x);
        return ret;
}
int main()
{
        cout << setprecision(8) << fixed;
        ll t;
        cin >> t;
        init();
        while(t--) {
                ll a,b;
                cin >> a >> b;
                if(b > a){
                        cout << "0\n"; continue;
                }else{
                        ld ans = 1.0;
                        if(b == 0 && a == 0) {
                                cout << "1\n"; continue;
                        }
                        if(a == b) {
                                cout << 1.0/(1.0 + 1.0*a) << "\n"; continue;
                        }
                        ans = a-b+1;
                        ans /= (ld)(1.0*a + 1.0);
                        cout << ans << "\n";
                }
        }
        return 0;
}
