#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int dp[1005][55];
int a[1005], pre[1005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    s++;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    for (int i = 0; i <= n; i++) for (int j = 0; j <= s; j++) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int x = 1; x <= s; x++)
            for (int j = i; j >= 1; j--)
                if (dp[j - 1][x - 1] != inf)
                    dp[i][x] = min(dp[i][x], max(dp[j - 1][x - 1], pre[i] - pre[j - 1]));
    cout << dp[n][s];
}
