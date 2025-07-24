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
	cout << '\n';
	while (q--)
	{
		int u, v; cin >> u >> v;
		if (u == v) {cout << n << '\n'; continue;}
			
		int x = lca(u, v);
		int du = d[u] - d[x], dv = d[v] - d[x], dic = du + dv;
		if (dic & 1) {cout << 0 << '\n'; continue;}
		dic /= 2;
		if (dic < du)
		{
			int lf = lift(u, dic), chil = lift(u, dic - 1);
			cout << cnt[lf] - cnt[chil] << '\n';
		}
		if (dic < dv)
		{
			int lf = lift(v, dic), chil = lift(v, dic - 1);
			cout << cnt[lf] - cnt[chil] << '\n';
		}
		if (dic == du)
		{
			int lf = lift(u, dic - 1), lr = lift(v, dic - 1);
			cout << n - cnt[lf] - cnt[lr] << '\n';
		}

	}
	/*while (q--)
	{
		int x; cin >> x;
		cout << cnt[x] << ' ';
	}*/
}
