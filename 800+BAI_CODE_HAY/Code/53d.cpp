#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
int a[500005],n,k;


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("TAPDT.INP","r",stdin);
    freopen("TAPDT.OUT","w",stdout);
    cin >> n >> k;
    int lim=0,pos=0;
    for (int i=1;i<=k;i++)
    {
        cin >> a[i];
        if (a[i]>lim) lim=a[i],pos=i;
    }
    n++;
    int res=0;
    for (int p=1;p<=n-lim;p++)
    {
        int cnt=1;
        for (int i=1;i<=k;i++)
        if (i!=pos)
        {
            int l=max(p-a[i]+1,1LL);
            int r=min(p+lim+a[i]-1,n);
            int len=r-l-a[i]+1;
            cnt=cnt*len%mode;
        }
        res=(res+cnt)%mode;

    }
    cout << res%mode;
}
