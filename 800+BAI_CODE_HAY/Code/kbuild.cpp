#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[200005];
int d[200005], p[200005], par[200005], ans;

void dfs(int u, int last = 0)
{
	for (int v : g[u]) if (v != last)
	{
		p[v] = u;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}
int find(int u)
{
	return (u == par[u]? u : par[u] = find(par[u]));
}
void get(int U, int V)
{
	int u = U, v = V;
	while (u != v)
	{
		u = find(u); v = find(v);
		if (u == v) return;
		int du = d[u], dv = d[v];
		if (du >= dv) u = par[u] = p[u], ans--;
		if (dv >= du) v = par[v] = p[v], ans--;
		//cout << u << ' ' << v << '\n';
	}	
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) par[i] = i;
	ans = n - 1;
	int q; cin >> q;
	while (q--)
	{
		int u, v; cin >> u >> v;
		get(u, v);
	}
	cout << ans;

}