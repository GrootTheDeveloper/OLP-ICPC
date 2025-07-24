#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second

vector <iii> Min, Max;
int a[1000006];

struct DSU
{
	vector <int> par, sz;
	void make(int n)
	{
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
	}
	int find(int v)
	{
		return (par[v] == v? v : par[v] = find(par[v]));
	}
	void Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
	int calc(int v)
	{
		return sz[find(v)];
	}
};


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		Max.push_back({max(a[u], a[v]), {u, v}});
		Min.push_back({min(a[u], a[v]), {u, v}});
	}
	sort(Max.begin(), end(Max));
	sort(Min.begin(), end(Min), greater<iii>());
	DSU d;
	d.make(n);
	int ans = 0;
	for (auto x : Max)
	{
		int w = x.fi, u = x.se.fi, v = x.se.se;
		ans += w * d.calc(u) * d.calc(v);
		d.Union(u, v);
	}
	d.make(n);
	for (auto x : Min)
	{
		int w = x.fi, u = x.se.fi, v = x.se.se;
		ans -= w * d.calc(u) * d.calc(v);
		d.Union(u, v);
	}
	cout << ans;
}