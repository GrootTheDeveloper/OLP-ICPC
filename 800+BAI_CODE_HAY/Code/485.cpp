#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define ii pair<int,int>
#define fi first
#define se second 
vector <int> g[100005];
int up[100005][18], d[100005], cnt[100005];

void dfs(int u, int p = 0)
{
	up[u][0] = p;
	cnt[u] = 1;
	for (int i = 1; i <= 17; i++) 
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
		cnt[u] += cnt[v];
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
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	return up[u][0];
}
int dis(int u, int v)
{
	int x = lca(u, v);
	return d[u] + d[v] - 2 * d[x];
}
int a[3], b[3];
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
		int cost = 1e9, res = 0;
		for (int i = 0; i < 3; i++) cin >> a[i];
		b[0] = 0; b[1] = 1; b[2] = 2;
		do
		{
			int x = b[0], y = b[1], z = b[2];
			int com = lca(a[x],a[y]);
			int new_cost = d[a[x]] + d[a[y]] - 2 * d[com] + dis(com, a[z]);
			if (new_cost < cost) cost = new_cost, res = com;
			//cout << "(" << a[x] <<  ' ' << a[y] << ' ' << a[z] << ") ";
		} while (next_permutation(b, b + 3));
		cout << res << '\n';
	}


}