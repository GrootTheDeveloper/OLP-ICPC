#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second

map<ii,bool> f;
ii op[200005];
int x[200005], y[200005], ans[200005];
struct DSU
{
	vector<int> par, sz;
	int cnt;	
	DSU (int n)
	{
		par.resize(n + 1);
		sz.resize(n + 1);
		cnt = n;
		for (int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
	}
	int find(int v) {return (v == par[v]? v : par[v] = find(par[v]));}
	void unite(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		--cnt;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{	
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i],y[i]);
	}
	for (int i = 1; i <= k; i++)
	{
		int u, v; cin >> u >> v;
		op[i] = {u,v};
		f[{min(u,v), max(u,v)}] = true;
	}
	DSU d(n);
	for (int i = 1; i <= m; i++)
		if (f.find({x[i], y[i]}) == f.end()) d.unite(x[i], y[i]);
	for (int i = k; i >= 1; i--)
	{
		ans[i] = d.cnt;
		d.unite(op[i].fi, op[i].se);
	}
	for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
}