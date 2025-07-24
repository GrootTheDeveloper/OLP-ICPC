#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define s first
#define t second
ii a[111];
int dp[111][111][111];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].t;
    sort(a + 1, a + n + 1,[](ii x, ii y)
    {
        return x.t < y.t;
    });
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
        {
            if (a[k].s > a[i].t)
                ans = max(ans, dp[k][j][k] = max(dp[k][j][k], dp[i][j][k - 1] + (a[k].t - a[k].s)));
            if (a[k].s > a[j].t)
                ans = max(ans, dp[i][k][k] = max(dp[i][k][k], dp[i][j][k - 1] + (a[k].t - a[k].s)));
            ans = max(ans, dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j][k]));
        }
    }
    cout << ans;
}
