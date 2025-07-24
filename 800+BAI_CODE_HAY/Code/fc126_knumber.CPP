#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int dp[1003], a[1003], dic[1003], last[1003];


void solve()
{
    int n; cin >> n;
    fill(last, last + n + 1, 0);
    fill(dic, dic + n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dic[a[i]] = max(dic[a[i]], i - last[a[i]]);
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    if (dic[i] != -1) dic[i] = max(dic[i], n - last[i] + 1);

    fill(dp, dp + n + 1, inf);
    for (int i = 1; i <= n; i++)
    if (dic[i] != -1) dp[dic[i]] = min(i, dp[dic[i]]);
    dp[0] = inf;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i]);
        cout << (dp[i] == inf? -1 : dp[i]) << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
