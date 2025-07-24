#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
int up[100005][18], d[100005], par[100005];
ii eg[100005];
int n, m;
vector <int> g[100005];
struct node
{
	int x, y, w;
} b[100005];

void dfs(int u, int p = 0)
{
	up[u][0] = p;
	par[u] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int id : g[u])
	{
		int v = eg[id].fi + eg[id].se - u;
		if (v != p) d[v] = d[u] + 1, dfs(v,u);
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
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}
bool sub1()
{
	if (m != 1) return 0;
	vector <bool> ans(n + 1, false);	

	int x = b[1].x, y = b[1].y;
	int cm = lca(x,y);
	while (x != cm)
	{
		ans[x] = true;
		x = up[x][0];
	}
	while (y != cm)
	{
		ans[y] = true;
		y = up[y][0];
	}
	ans[cm] = true;
	for (int i = 1; i < n; i++)
		if (ans[eg[i].fi] && ans[eg[i].se])
			cout << b[1].w << ' ';
		else cout << 1 << ' ';
	return true;
}
bool sub2()
{
	if (n > 5000 || m > 5000) return false;
	vector <vector<int>> val(n + 2, vector<int> (n + 2, 0));
	for (int i = 1; i <= m; i++)
	{
		int x = b[i].x, y = b[i].y, w = b[i].w;
		int cm = lca(x, y);
		int cnt = 0;
		while (x != cm)
		{
			if (val[x][par[x]] == 0)
				val[x][par[x]] = val[par[x]][x] = w;
			if (val[x][par[x]] < w) return cout  << -1, 1;
			cnt += (val[x][par[x]] == w);
			x = par[x];
		}
		while (y != cm)
		{
			if (val[y][par[y]] == 0)
				val[y][par[y]] = val[par[y]][y] = w;
			if (val[y][par[y]] < w) return cout  << -1, 1;
			cnt += (val[y][par[y]] == w);
			y = par[y];
		}
		if (cnt == 0) return cout << -1, true;
	}
	for (int i = 1; i < n; i++)
		cout << (val[eg[i].fi][eg[i].se]? val[eg[i].fi][eg[i].se] : 1) << ' ';
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		eg[i] = {u,v};
		g[u].push_back(i);
		g[v].push_back(i);
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i].x >> b[i].y >> b[i].w;
	dfs(1);
	if (sub1()) return 0;
	if (sub2()) return 0;
}