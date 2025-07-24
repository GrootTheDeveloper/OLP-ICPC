#include <bits/stdc++.h>
using namespace std;

int dp[1000006][3];
char a[1000006];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        fill(dp[i], dp[i] + 3, -1e9);
    if (a[1] == '?') dp[1][1] = dp[1][2] = 0;
    else dp[1][a[1] - 'a' + 1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (a[i] == '?')
        {
            for (int cur = 1; cur <= 2; cur++)
            for (int last = 1; last <= 2; last++)
                dp[i][cur] = max(dp[i][cur], dp[i - 1][last] + cur - last);
        } else
        {
            int cur = a[i] - 'a' + 1;
            for (int last = 1; last <= 2; last++)
                dp[i][cur] = max(dp[i][cur], dp[i - 1][last] + cur - last);
        }
    }
    cout << max(dp[n][1], dp[n][2]);
}
