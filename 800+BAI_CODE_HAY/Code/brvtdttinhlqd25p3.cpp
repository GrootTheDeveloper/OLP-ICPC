#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int up[200005][19], d[200005], sz[200005];

void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 18; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	sz[u] = 1;

	for (int v : g[u])
	if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int lift(int u, int k)
{
	for (int i = 18; i >= 0; i--)
	if (k >> i & 1) u = up[u][i];
	return u;
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	v = lift(v, d[v] - d[u]);
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (up[u][i] != up[v][i]) 
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("CHILLIS.INP","r",stdin);
	freopen("CHILLIS.OUT","w",stdout);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	if (n > 2000) return 0;
	int ans = n;
	for (int u = 1; u <= n; u++)
	for (int v = u + 1; v <= n; v++)
	{
		int x = lca(u, v);
		if (x != u && x != v)
			ans = min(ans, max({sz[u], sz[v], n - (sz[u] + sz[v])}) - min({sz[u], sz[v], n - (sz[u] + sz[v])}));
		else if (x == u)
			ans = min(ans, max({sz[v], sz[u] - sz[v], n - sz[u]}) - min({sz[v], sz[u] - sz[v], n - sz[u]}));
		else if (x == v)
			ans = min(ans, max({sz[u], sz[v] - sz[u], n - sz[v]}) - min({sz[u], sz[v] - sz[u], n - sz[v]}));

	}
	cout << ans;
}