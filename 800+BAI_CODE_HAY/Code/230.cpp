#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first 
#define se second
int dp[2][100005], par[100005], d[100005];
priority_queue <ii> q;
vector <int> g[100005];
void dfs(int u, int p = 0)
{
	dp[1][u] = 1;
	for (int v : g[u])
	{
		if (v == p) continue;
		d[v] = d[u] + 1;
		par[v] = u;
		q.push({d[v], v});
		dfs(v,u);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int v = top.se, u = par[v];
		dp[0][u] += max(dp[1][v], dp[0][v]);
		dp[1][u] += dp[0][v];
	}
	cout << max(dp[1][1], dp[0][1]);
}