#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1006][1006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin >> a[i][j];
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        int x=i,y=j,MAX=a[i][j]+a[i][j+1]+a[i][j-1]+a[i-1][j]+a[i+1][j],temp=MAX;
        if (i-1!=0 && temp<MAX-2*(a[i][j]+a[i-1][j])) temp=MAX-2*(a[i][j]+a[i-1][j]),x=i-1,y=j;
        if (i+1!=n+1 && temp<MAX-2*(a[i][j]+a[i+1][j])) temp=MAX-2*(a[i][j]+a[i+1][j]),x=i+1,y=j;
        if (j-1!=0 && temp<MAX-2*(a[i][j]+a[i][j-1])) temp=MAX-2*(a[i][j]+a[i][j-1]),y=j-1,x=i;
        if (j+1!=m+1 && temp<MAX-2*(a[i][j]+a[i][j+1])) temp=MAX-2*(a[i][j]+a[i][j+1]),y=j+1,x=i;
        if (x!=i || y!=j) a[i][j]*=-1,a[x][y]*=-1;
    }
    int sum=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) sum+=a[i][j];
    return cout << sum,0;
}
