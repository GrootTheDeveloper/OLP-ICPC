#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int t, d, p;
    bool operator< (const node &other) const
    {
        return d < other.d;
    }
}a[111];
int dp[2222];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int lim = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].d >> a[i].p, lim = max(lim, a[i].d);
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i].d - a[i].t - 1; j >= 0; j--)
            if (dp[j] != -1) dp[j + a[i].t] = max(dp[j + a[i].t], dp[j] + a[i].p);
    int res = 0;
    for (int i = 1; i <= lim; i++) res = max(res, dp[i]);
    cout << res;
}
