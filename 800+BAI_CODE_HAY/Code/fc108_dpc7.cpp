#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300005], dp[300005][3];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        dp[i][0] = max(0ll, dp[i - 1][0] + a[i]);
    for (int i = 1; i <= n; i++)
        dp[i][1] = max({dp[i][0], dp[i - 1][1] + a[i] * x, 0ll});
    for (int i = 1; i <= n; i++)
        dp[i][2] = max(dp[i][1] , max(dp[i - 1][1], dp[i - 1][2]) + a[i]);
    int ans = -1e18;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][2]);
    cout << ans;
}
