#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[100005];
int dp[100005][101], n, k, res, d[101];

void dfs(int u, int p = 0)
{
    dp[u][0] = 1;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        for (int i = 1; i <= k; i++)
        {
            d[i] = dp[v][i - 1];
            res += d[i] * dp[u][k - i];
        }
        for (int i = 1; i <= k; i++) dp[u][i] += d[i];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << res;
}
