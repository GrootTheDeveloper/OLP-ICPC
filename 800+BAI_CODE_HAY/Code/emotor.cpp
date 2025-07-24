#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second

struct node
{
	int x,y,w;
	bool operator< (const node &other) const{
		return w < other.w;
	}
}g[10004];
struct query
{
	int x, w, id;
	bool operator< (const query &other) const{
		return w < other.w;
	}
}op[80005];

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
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
	}
	int calc(int v)
	{
		v = find(v);
		return sz[v];
	}
};
int ans[80005];
void solve()
{
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
		cin >> g[i].x >> g[i].y >> g[i].w;
	for (int i = 1; i <= q; i++)
	{
		cin >> op[i].x >> op[i].w;
		op[i].id = i;
	}
	DSU d(n);
	sort(g + 1, g + m + 1);
	sort(op + 1, op + q + 1);
	int idx = 1;
	for (int i = 1; i <= q; i++)
	{
		while (g[idx].w <= op[i].w && idx <= m) 
			d.Union(g[idx].x, g[idx].y), idx++;
		ans[op[i].id] = d.calc(op[i].x);
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}