#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int a[111], dp[111][111];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("RUTBAI.INP","r",stdin);
    freopen("RUTBAI.OUT","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dp[i][j] = inf;
    for (int i = 1; i < n; i++) dp[i][i + 1] = 0;
    for (int i = 1; i <= n - 2; i++) dp[i][i + 2] = a[i] * a[i + 1] * a[i + 2];

    for (int len = 3; len < n; len++)
        for (int i = 1; i + len <= n; i++)
            for (int j = i + 1; j < i + len; j++)
                dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j][i + len] + a[i] * a[j] * a[i + len]);
    cout << dp[1][n];
}
