#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool mark[100005];
vector <int> g[100005];
void dfs(int u)
{
    mark[u] = true;
    for (int v : g[u])
    {
        if (!mark[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!mark[i]) dfs(i);
    cout << *max_element(dp + 1, dp + n + 1);
}
