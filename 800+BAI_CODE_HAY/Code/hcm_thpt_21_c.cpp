#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[555][555],f[555][555];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=0;i<=n+1;i++) f[0][i]=f[i][0]=f[i][n+1]=f[n+1][i]=INT_MAX;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin >> a[i][j];
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) f[i][j]=min({f[i-1][j],f[i-1][j-1],f[i-1][j+1],f[i][j-1]})+a[i][j];
    int res=0;
    int x=n,y=n;
    while (x!=1 && y!=1)
    {
        int h=x,k=y-1;
        if (f[x][y-1]<f[h][k]) h=x,k=y-1;
        if (f[x-1][y]<f[h][k]) h=x-1,k=y;
        if (f[x-1][y-1]<f[h][k]) h=x-1,y=k-1;
        if (f[x-1][y+1]<f[h][k]) h=x-1,k=y+1;
        res=max(res,abs(a[x][y]-a[h][k]));
        x=h;y=k;
    }
    cout << res;
}
