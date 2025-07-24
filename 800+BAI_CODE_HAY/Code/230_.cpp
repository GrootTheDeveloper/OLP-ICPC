#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005][2];
vector <int> g[100005];
int ans;

void dfs(int u, int p = 0)
{
    dp[u][1] = 1;
    dp[u][0] = 0;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);

}
