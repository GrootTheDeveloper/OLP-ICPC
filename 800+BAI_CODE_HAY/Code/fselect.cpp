#include <bits/stdc++.h>
using namespace std;
#define int long long
int root, d[200005], up[200005][19], k, n;
vector <int> group[100005], g[200005];
void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i <= 18; i++) 
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}
int lift(int v, int k)
{
	for (int i = 18; i >= 0; i--)
		if (k >> i & 1) v = up[v][i];
	return v;
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	v = lift(v, d[v] - d[u]);
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	return up[u][0];
}
void process()
{
	for (int pos = 1; pos <= k; pos++)
	{
		int lower = group[pos].back();
		for (auto x : group[pos])
			if (d[x] > d[lower]) lower = x;
		int res = 0;
		for (auto x : group[pos])
		{
			int par = lca(x, lower);
			res = max(res, d[x] + d[lower] - 2 * d[par]);
		}
		cout << res << '\n';

	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		group[x].push_back(i);
		if (y == 0) root = i;
		else
		{
			g[i].push_back(y);
			g[y].push_back(i);
		}
	}
	dfs(root);
	process();
}