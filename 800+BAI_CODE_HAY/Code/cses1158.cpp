#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e5+5
int dp[1001][MAX],h[1001],s[1001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<=n; i++)
        for (int j=1;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            if (j>=h[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-h[i]]+s[i]);
        }
    cout << dp[n][x];
    return 0;
}
