#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, lim;
int a[3333];

void sub1()
{
    vector<vector<int>> dp(n + 1, vector<int> (lim + 1, 1));
    for (int x = 1; x <= lim; x++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = i - 1; j >= 1; j--)
                if (a[i] - a[j] == x) dp[i][x] = max(dp[i][x], dp[j][x] + 1);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= lim; j++)
        res = max(res, dp[i][j]);
    cout << res;
}
int cnt[3003];
void sub2()
{
    vector<vector<int>> dp(n + 1, vector<int> (lim + 1, 1));
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            if (a[i] - a[j] > 0)
            {
                int x = a[i] - a[j];
                dp[i][x] = max(dp[i][x], dp[j][x] + 1);
            }
    int res = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= lim; j++)
        res = max(res, dp[i][j]);
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]);
    if (n <= 100) sub1();
    else sub2();

}
