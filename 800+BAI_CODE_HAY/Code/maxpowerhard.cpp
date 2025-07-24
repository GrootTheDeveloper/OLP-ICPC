#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,n;

void solve()
{
    int res=(int)1e18;
    int lim=trunc(sqrt(m));
    for (int i=2;i<=lim;i++)
    {
        if (m%i==0)
        {
            int cnt=0;
            while (m%i==0) cnt++,m/=i;
            int k=i,mask=0;
            while (k<=n) mask+=n/k,k*=i;
            res=min(res,mask/cnt);
        }
    }
    if (m!=1)
    {
        int k=m,mask=0;
        while (k<=n) mask+=n/k,k*=m;
        res=min(res,mask);
    }
    if (res==0) res=-1;
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    solve();
}
