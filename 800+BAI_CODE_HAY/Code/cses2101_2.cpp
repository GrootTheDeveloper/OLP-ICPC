#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second 

iii eg[200005];
vector <ii> g[200005];
int up[200005][19], fh[200005][19], d[200005];
struct DSU
{
	vector <int> par, sz;
	DSU (int n)
	{
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++)  
		{
			par[i] = i;
			sz[i]  = 1;
		}
	}
	int find(int v)
	{
		return ((v == par[v])? v : par[v] = find(par[v]));
	}
	bool Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
		return true;
	}
	bool check(int a, int b)
	{
		a = find(a); b = find(b);
		return a == b;
	}
};

void dfs_pre(int u, int p = - 1, int w = 1e9)
{
	up[u][0] = p;
	fh[u][0] = w;
	for (int i = 1; i <= 18; i++)
	{
		fh[u][i] = max(fh[u][i - 1], fh[up[u][i - 1]][i - 1]);
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (auto x : g[u])
	{
		int v = x.fi, w = x.se;
		if (v == p) continue;
		d[v] = d[u] + 1;
		dfs_pre(v,u,w);
	}	
}
int calc(int u, int v)
{
	int res = 0;
	if (d[u] > d[v]) swap(u,v);
	for (int i = 18; i >= 0; i--)
	{
		if ((d[v] - d[u]) >> i&1)
		{
			res = max(res, fh[v][i]);
			v   = up[v][i];
		}
	}
	if (u == v) return res;
	for (int i = 18; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
		{
			res = max({res, fh[u][i], fh[v][i]});
			u = up[u][i];
			v = up[v][i];
		}
	}
	res = max({res, fh[u][0], fh[v][0]});
	return res;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,q; cin >>  n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int u,v; cin >> u >> v;
		eg[i] = {i,{u,v}};
	}
	sort(eg + m, eg + m + 1);
	DSU dsu(n);
	for (int i = 1; i <= m; i++)
	{
		int u = eg[i].se.fi, v = eg[i].se.se, w = eg[i].fi;
		if (dsu.Union(eg[i].se.fi, eg[i].se.se))
		{
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	dfs_pre(1);
	while (q--)
	{
		int u,v; cin >> u >> v;
		if (dsu.check(u,v)) cout << calc(u,v) << '\n';
		else cout << -1 << '\n';
	}
}