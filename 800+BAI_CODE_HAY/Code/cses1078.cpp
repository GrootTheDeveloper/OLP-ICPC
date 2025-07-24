#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mode 1000000007

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n,m; cin >> n >> m;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            dp[i][j]=a[i][j]=0;
    while (m--)
    {
        int x,y;
        cin >> x >> y;
        a[x][y]=1;
    }
    if (a[1][1]==1 || a[n][n]==1) return cout << 0,0;
    dp[1][1]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]!=1 && i+j!=2) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mode;

    cout << dp[n][n]%mode;
    return 0;

}
