#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
vector <ii> g[100005];
int up[100005][18], d[100005], dic[100005];
void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto x : g[u]) 
	{
		int v = x.fi, w = x.se;
		if (v == p) continue;
		dic[v] = dic[u] + w;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
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
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	dfs(1);
	while (q--)
	{
		int x, y; cin >> x >> y;
		int mc = lca(x, y);
		cout << dic[x] + dic[y] - 2 * dic[mc] << '\n';
	}
}
