#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
int a[1111],dp[1111];

main()
{
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (a[j]<=i) dp[i]=(dp[i]+dp[i-a[j]])%mode;
            else break;
    }
    cout << dp[m]%mode;
}
