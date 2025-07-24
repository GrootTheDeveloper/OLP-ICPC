#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
int a[100005];
iii eg[100005];
bool cmp(iii a, iii b)
{
	return a.fi < b.fi;
}

struct DSU
{
	vector <int> par, sz, val;
	int ans = 0;
	DSU (int n)
	{
		par.resize(n + 5);
		sz.resize(n + 5);
		val.resize(n + 5);
		for (int i = 1; i <= n; i++)
			par[i] = i, val[i] = a[i], sz[i] = 1;
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void Union(int a, int b)
	{
		a = find(a);; b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b]; 
		ans += (val[a] + val[b]);
		val[a] = max(val[a], val[b]);
	}
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		eg[i] = {max(a[u], a[v]), {u, v}};
	}
	sort(eg + 1, eg + n, cmp);
	DSU d(n);
	for (int i = 1; i < n; i++)
		d.Union(eg[i].se.fi, eg[i].se.se);
	cout << d.ans;
}