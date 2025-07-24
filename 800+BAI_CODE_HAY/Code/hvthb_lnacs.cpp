#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1005], b[1005], dp[1005][1005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("lnacs.inp","r",stdin);
    freopen("lnacs.out","w",stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    for (int i = 1; i <= m; i++) dp[1][i] = (a[1] == b[i]);
    for (int i = 1; i <= n; i++) dp[i][1] = (b[1] == a[i]);

    for (int i = 2; i <= n; i++) for (int j = 2; j <= m; j++)
        if (a[i] == b[j]) dp[i][j] = dp[i - 2][j - 2] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[n][m];

}
