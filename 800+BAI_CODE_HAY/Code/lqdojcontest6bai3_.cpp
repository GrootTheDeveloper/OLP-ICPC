#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
iii eg[500005];
int ans[300005], a[300005], id[300005];
struct DSU
{
	vector <int> par, sz;
	int ans = 0;
	DSU (int n)
	{
		par.resize(n + 1);
		sz.resize(n  + 1);
		for (int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	int calc(int n)
	{
		return n * (n - 1) / 2;
	}
	void Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		ans -= calc(sz[a]) + calc(sz[b]);
		ans += calc(sz[a] + sz[b]);
		par[b] = a;
		sz[a] += sz[b];

	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("TRAVEL.INP","r",stdin);
	freopen("TRAVEL.OUT","w",stdout);
	int o; cin >> o;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg[i] = {w,{u,v}};
	}
	sort(eg + 1, eg + m + 1);
	int q; cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> a[i];
	iota(id + 1, id + q + 1, 1);
	sort(id + 1, id + q + 1, [](int x, int y)
	{
		return a[x] < a[y];
	});
	DSU d(n);
	int l = 1;
	for (int i = 1; i <= q; i++)
	{
		while (eg[l].fi <= a[id[i]] && l <= m)
			d.Union(eg[l].se.fi, eg[l].se.se), l++;
		ans[id[i]] = d.ans;
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}