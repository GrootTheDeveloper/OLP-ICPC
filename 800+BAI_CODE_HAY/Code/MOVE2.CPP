#include <bits/stdc++.h>
using namespace std;

struct node
{
	int delta_temp, u, v;
	bool operator < (const node &other) const
	{
		return delta_temp < other.delta_temp;
	}
}eg[200005];
int par[100005], sz[100005], a[100005];
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}
void merge(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, s, t; cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		eg[i] = {abs(a[u] - a[v]), u, v};
	}	
	sort(eg + 1, eg + m + 1);
	make_set(n);
	for (int i = 1; i <= m; i++)
	{
		merge(eg[i].u, eg[i].v);
		if (Find(s) == Find(t)) 
			return cout << eg[i].delta_temp, 0;
	}
	cout << -1;
}