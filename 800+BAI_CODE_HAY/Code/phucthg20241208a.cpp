#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int u, int p = 0)
{
    sz[u] = 1;
    dp[u][0] = 1;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        sz[u] += sz[v];
        for (int i = sz[u]; i >= 1; i--)
        for (int j = 1; j <= min(sz[v], i - 1); j++)
            dp[u][i] = max(dp[u][i], dp[u][i - j] * )

    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie0(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= sz[1]; i++)
        ans = max(ans, dp[1][i]);
    cout << ans;
}
