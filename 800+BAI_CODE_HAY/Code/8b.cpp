#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("gcdpow.inp","r",stdin);
    freopen("gcdpow.out","w",stdout);
    int t,a,b,n; cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        int k=gcd(a,b),x=k,res=k,t=x;
        if (k==1) { cout << 1 << '\n';continue;}
        while (x<b && n!=0)
        {
            x*=k;
            if (x<t) break;
            t=x;
            res=max(res,gcd(x,b));
            n--;
        }
        cout << res << '\n';

    }

}
