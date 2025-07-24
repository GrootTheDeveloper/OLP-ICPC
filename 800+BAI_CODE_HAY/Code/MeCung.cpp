#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[22][22],d,ma=400,m,n;
void go(int x, int y)
{
    if (a[x][y]==0)
    {
        d+=1;
        a[x][y]=1;
    }
    else return;
    if (x==m && y==n)
    {
        ma=min(ma,d);
        if (ma==m*2-1) return;
    }

    go(x,y+1);
    go(x,y-1);
    go(x+1,y);
    go(x-1,y);
    d-=1;
    a[x][y]=0;
}
main()
{
    for (int i=0; i<22; i++)
        for (int j=0; j<22; j++)
            a[i][j]=1;
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    for (int i=0; i<=m+1; i++)
    go(1,1);
    cout << ma;

}
