#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mode 1000000007

main()
{
    ll n; cin >> n;
    ll dp[n+1][n+1];
    char a[n+1][n+1];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            dp[i][j]=0;
        }

    if (a[1][1]=='*' || a[n][n]=='*') return cout << 0,0;

    for (int i=1;i<=n;i++)
        dp[i][0]=dp[0][i]=0;
    dp[1][1]=1;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]!='*' && i+j!=2) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mode;

    cout << dp[n][n]%mode;
    return 0;

}
