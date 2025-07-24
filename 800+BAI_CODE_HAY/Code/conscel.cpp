#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1111][1111],a[1111][1111],
 dx[4]={-1,1,0,0},
 dy[4]={0,0,-1,1};
void Try(int x, int y)
{
    if (a[x][y]==0) return;
    for (int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if (a[nx][ny]-a[x][y]==1)
        {
            if (f[nx][ny]==1) Try(nx,ny);
            f[x][y]=max(f[x][y],f[nx][ny]+1);
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> m >> n;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j],f[i][j]=1;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
        Try(i,j);
    int res=0;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) res=max(res,f[i][j]);
    cout << res;


}
