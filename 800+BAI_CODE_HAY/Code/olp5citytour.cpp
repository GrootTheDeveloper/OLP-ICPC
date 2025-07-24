#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,b[400005],f[400005],use[400005];
void sub1()
{
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) f[i]=b[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++) if (b[i]-b[j]==i-j) f[i]=max(f[i],f[j]+b[i]);
    }
    int res=1;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    cout << res;
}
void sub2()
{
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) f[i]=b[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++) if (b[i]-b[j]==i-j) f[i]=max(f[i],f[j]+b[i]);
    }
    int res=1;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    cout << res;

}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    if (k==0) sub1();
    if (k==1) sub2();

}
