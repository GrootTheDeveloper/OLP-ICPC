#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> g[100005];
int dp[100005], val[100005];
int res = -1e15;
void dfs(int u, int p = 0)
{
	dp[u] = val[u];
	int ans = 0;
	for (int v : g[u]) if (v != p)
	{
		dfs(v, u);
        res = max(res, ans + val[u] + dp[v]);
        dp[u] = max(dp[u], dp[v] + val[u]);
        ans = max(ans, dp[v]);
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i], res = max(res, val[i]);
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << res;
}
