#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int ans[N], d[N], up[N][18], sz[N], par[N];
vector <int> g[N];
bool del[N];
int n, m;
void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		{
			d[v] = d[u] + 1;
			dfs(v, u);
		}
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	for (int i = 17; i >= 0; i--)
		if ((d[v] - d[u]) >> i & 1) v = up[v][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[v][i] != up[u][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}
int dist(int u, int v)
{
	int x = lca(u, v);
	return d[v] + d[u] - 2 * d[x];
}
void calc_size(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	if (v != p && !del[v])
		calc_size(v, u), sz[u] += sz[v];
}
int get(int u, int p, int n)
{
	for (int v : g[u])
		if (v != p && !del[v] && sz[v] > n / 2)
			return get(v, u, n);
	return u;
}
void build(int u, int p = 0)
{
	calc_size(u);
	int x = get(u, 0, sz[u]);
	par[x] = p;
	del[x] = true;
	for (int v : g[x])
	if (!del[v]) build(v, x);
}

void update(int x)
{
	int u = x;
	while (u != 0)
	{
		int dis = dist(u, x);
		ans[u] = min(ans[u], dis);
		u = par[u];
	}
}
int Ans(int x)
{
	int u = x;
	int res = inf;
	while (u != 0)
	{
		int dis = dist(x, u);
		res = min(res, dis + ans[u]);
		u = par[u];
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	build(1);
	fill(ans, ans + n + 1, inf);
	update(1);
	while (m--)
	{
		int kind, u; cin >> kind >> u;
		if (kind == 1) update(u);
		else cout << Ans(u) << '\n';
	}
}