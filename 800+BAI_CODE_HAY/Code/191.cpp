#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> g[100005];
int up[100005][18], d[100005];
void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		d[v] = d[u] + 1,dfs(v, u);
}
int lift(int v, int k)
{
	for (int i = 17; i >= 0; i--)
		if (k >> i & 1) v = up[v][i];
	return v;
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u,v);
	v = lift(v, d[v] - d[u]);
	if (v == u) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) 
			v = up[v][i], u = up[u][i];
	return up[u][0];
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << lca(x, y) << ' ';
	}
}