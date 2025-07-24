#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1003][1003], pre[1003], a[1003];
const int inf = 1e15;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int x = pre[n] / n, k = pre[n] % n;

    for (int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + k + 1, inf);

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + abs(pre[i] - i * x);
        for (int j = 1; j <= min(k, i); j++)
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + abs(pre[i] - (i * x + j));
    }
    cout << dp[n][k];
}
