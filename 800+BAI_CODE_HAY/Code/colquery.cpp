#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
map <int,int> col[100005];

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
			col[i][a[i]]++;
			sz[i] = 1;
		}
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void Join(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		for (auto it : col[b]) col[a][it.first] += it.second;
		col[b].clear();
	}
	int calc(int v, int c)
	{
		v = find(v);
		return (col[v].find(c) != col[v].end() ? col[v][c] : 0);
	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	DSU d(n);
	while (q--)
	{
		int kind, u, v; cin >> kind >> u >> v;
		if (kind == 1)
			d.Join(u, v);
		else cout << d.calc(u, v) << '\n';
	}
}