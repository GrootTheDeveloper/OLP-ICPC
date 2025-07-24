#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005][2], l[100005], r[100005];
vector <int> g[100005];
void dfs(int u, int p = 0)
{
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}
