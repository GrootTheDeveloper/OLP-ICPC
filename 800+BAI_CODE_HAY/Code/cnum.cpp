#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006], dp[3][1000006];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = dp[1][i - 1] + (a[i] != 1);
        dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + (a[i] != 2);
    }
    cout << min(dp[1][n], dp[2][n]);
}
