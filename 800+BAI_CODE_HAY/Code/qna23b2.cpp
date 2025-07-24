#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;
int a[5001], dp[5001][5001];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) dp[i][i + 1] = 0;
    for (int i = 1; i <= n - 2; i++) dp[i][i+2] = (a[i] - a[i + 2]) * (a[i] - a[i+2]);

    for (int k = 3; k <= n - 1; k++)
        for (int i = 1; i <= n - k; i++)
        {
            dp[i][i + k] = inf;
            for (int j = i + 1; j <= i + k - 1; j++)
                dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j][i + k] + (a[i] - a[i+k]) * (a[i] - a[i+k]));
        }
    cout << dp[1][n];
}
