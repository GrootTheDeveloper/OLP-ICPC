#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[3][100005], a[100005], b[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    dp[1][1] = a[1];
    dp[2][1] = b[1];
    for (int i = 2; i <= n; i++)
    {
        dp[1][i] = max(dp[2][i - 2] + a[i - 1] + a[i], dp[2][i - 1] + a[i]);
        dp[2][i] = max(dp[1][i - 2] + b[i - 1] + b[i], dp[1][i - 1] + b[i]);
    }
    cout << max(dp[1][n], dp[2][n]);
}
