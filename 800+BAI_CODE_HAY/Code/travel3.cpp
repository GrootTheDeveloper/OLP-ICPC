#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9 + 1e5 + 105;
int par[N], sz[N], up[N][18], d[N], ans[N];
bool del[N];
vector <int> g[N];
void init(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : g[u])
	if (v != p)
	{
		d[v] = d[u] + 1;
		init(v, u);
	}
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	for (int i = 17; i >= 0; i--)
		if ((d[v] - d[u]) >> i & 1) v = up[v][i];
	if (v == u) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}
int dist(int u, int v)
{
	int x = lca(u, v);
	return d[u] + d[v] - 2 * d[x];
}
int get(int u, int p, int n)
{
	for (int v : g[u])
		if (v != p && !del[v] && sz[v] > n/2)
			return get(v, u, n);
	return u;
}
void calc_size(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	if (v != p && !del[v])
		calc_size(v, u), sz[u] += sz[v];
}
void build(int u, int p = 0)
{
	calc_size(u);
	int x = get(u, 0, sz[u]);
	par[x] = p, del[x] = true;
	for (int v : g[x])
		if (!del[v]) build(v, x);
}

void update(int x, int cost)
{
	for (int u = x; u; u = par[u])
	{
		int dis = dist(u, x);
		ans[u] = min(ans[u], dis + cost);
	}
}
int Ans(int x)
{
	int res = inf;
	for (int u = x; u; u = par[u])
	{
		int dis = dist(u, x);
		res = min(res, dis + ans[u]);
	}
	return res;
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
	init(1);
	fill(ans, ans + n + 1, inf);
	build(1);
	while (q--)
	{
		int kind, u, cost;
		cin >> kind >> u;
		if (kind == 1)
		{
			cin >> cost;
			update(u, cost);
		}
		if (kind == 2) cout << min(d[u], Ans(u)) << '\n';
	}
}




