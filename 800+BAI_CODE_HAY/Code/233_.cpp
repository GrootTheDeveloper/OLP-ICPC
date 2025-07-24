#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[555][555], dp[555][555], n, l, s[555];
vector <int> g[555];

void dfs(int u, int p = 0)
{
    for (int i = 0; i <= s[u]; i++) dp[u][i] = a[u][i];
    vector <int> d(s[u] + 1, 0);
    for (int v : g[u])
    {
        dfs(v, u);
        for (int i = 0; i <= s[u]; i++)
            for (int j = 0; j <= min(i, s[v]); j++)
                d[i] = max(d[i], dp[v][j] + dp[u][i - j]);
        for (int i = 0; i <= s[u]; i++) dp[u][i] = max(dp[u][i], d[i]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int i = 2; i <= n; i++)
    {
        int u; cin >> u;
        g[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= l; j++)
            cin >> a[i][j];
    dfs(1);
    int res = 0;
    for (int i = 0; i <= s[1]; i++) res = max(res, dp[1][i]);
    cout << res;

}
