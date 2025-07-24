#include <bits/stdc++.h>
using namespace std;

int dp[1000006][2], a[1000006];
vector<int> g[1000006];
void dfs(int u, int p = 0)
{
	dp[u][1] = a[u];
	for (int v : g[u]) if (v != p)
	{
		dfs(v, u);
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];	
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][1], dp[1][0]);
}