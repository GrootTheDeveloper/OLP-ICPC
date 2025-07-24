#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[3003][3003], opt[3003][3003];
int a[3003], pre[3003];

int sqr(int n) {return n * n;}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        opt[i][i] = i;
        dp[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    for (int j = i + 1; j <= n; j++)
    for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++)
    {
        int tmp = dp[i][k] + dp[k + 1][j] + sqr(pre[j] - pre[i - 1]);
        if (tmp < dp[i][j])
        {
            dp[i][j] = tmp;
            opt[i][j] = k;
        }
    }
    cout << dp[1][n];
}
