#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int up[2002][12], sz[N], d[N];
vector<int> g[N];
int n;
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	up[u][0] = p;
	for (int i = 1; i <= 11; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];

	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}

}
int lift(int v, int k)
{
	for (int i = 11; i >= 0; i--)
	if (k >> i & 1) v = up[v][i];
	return v;
}

int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	v = lift(v, d[v] - d[u]);
	if (u == v) return u;
	for (int i = 11; i >= 0; i--)
	if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

void sub1()
{
	dfs(1);
	int ans = INT_MAX;
	for (int u = 1; u <= n; u++)
	for (int v = u + 1; v <= n; v++)
	{
		int x = lca(u, v);
		int a = sz[u], b = sz[v];
		if (x == u) a -= b;
		if (x == v) b -= a;
		int c = sz[1] - (a + b);
		ans = min(ans, max({a, b, c}) - min({a, b, c}));
	}
	cout << ans;
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.tie(0);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n <= 2000) sub1();
}