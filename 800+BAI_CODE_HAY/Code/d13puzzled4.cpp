#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[2002][2002];
int n, m, k, l;
void sub1()
{
    int x, y; cin >> x >> y;
    if (x != m) swap(x, y);
    if ((x != m && y != n) || ((m * n) & 1) ) return cout << 0, void();
    for (int i = 2; i <= n; i+=2) dp[1][i] = 1;
    for (int i = 2; i <= m; i+=2) dp[i][1] = 1;
    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] += (dp[i - 2][j] + dp[i][j - 1] - dp[i - 2][j - 1] + mode * mode) % mode;
            dp[i][j] %= mode;
            dp[i][j] += (dp[i][j - 2] + dp[i - 1][j] - dp[i - 1][j - 2] + mode * mode) % mode;
            dp[i][j] %= mode;
        }
    cout << dp[m][n];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k >> l;
    if (k != 1) return 0;
    sub1();
}
