#include <bits/stdc++.h>
using namespace std;
#define int long long
int pos[1111],sum[1000006],a[1000006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("EXLIST.INP","r",stdin);
    freopen("EXLIST.OUT","w",stdout);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
        if (pos[a[i]]==0) pos[a[i]]=i;
    }
    int len=0,s=0;
    for (int i=1;i<=n;i++)
    {
        if (i-pos[a[i]]+1>len)
        {
            len=i-pos[a[i]]+1;
            s=sum[i]-sum[pos[a[i]]-1];
        }
        if (i-pos[a[i]]+1==len) s=max(s,sum[i]-sum[pos[a[i]]-1]);
    }
    cout << len << ' ' << s;
}
