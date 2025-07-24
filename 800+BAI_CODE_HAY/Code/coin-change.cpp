#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[500],c[55];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m; cin >> n >> m;
    for (int i=1;i<=m;i++) cin >> c[i];
    dp[0]=1;
    for (int i=1;i<=m;i++)
        for (int j=0;j<=n-c[i];j++) dp[j+c[i]]+=dp[j];
    cout << dp[n];
}
