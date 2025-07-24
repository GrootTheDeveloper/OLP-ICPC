#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[6][100005];
int a[100005];
int n, k;
void sub1()
{
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = -1e15;
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = a[i];
        for (int j = i - 1; j >= 1; j--)
            for (int x = k; x > 1; x--)
                dp[x][i] = max(dp[x][i], dp[x - 1][j] + a[i] * x);
    }
    int ans = -1e15;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[k][i]);
    cout << ans << ' ';
}
priority_queue <int> q[6];
void sub2()
{
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = -1e15;

    q[0].push(0);
    for (int i = 1; i <= n; i++)
    {
        for (int x = k; x >= 1; x--)
        if (q[x - 1].size())
        {
            dp[x][i] = q[x - 1].top() + x * a[i];
            q[x].push(dp[x][i]);
        }
    }
    int ans = -1e15;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[k][i]);
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sub2();
}
