#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 3e5 + 5;

vector <int> g[maxn];
int d[maxn], par[maxn][19], n;

void dfs(int u, int p)
{
	par[u][0] = p;
	for (int i = 1; i <= 18; i++)
		par[u][i] = par[par[u][i-1]][i-1];

	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v,u);
	}
}
int lift(int u, int k)
{
	for (int i = 18; i >= 0; i--)
		if (k >> i & 1)
			u = par[u][i];
	return u;
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u,v);
	v = lift(v, d[v] - d[u]);
	if (u == v) return v;
	
	for (int i = 18; i >= 0; i--)
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	return par[u][0];
}

void inp()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
}
void solve()
{
	int q; cin >> q;
	while (q --)
	{
		int a,b,c;
		cin >> a >> b >> c;

		int x = lca(a,b);

		int dis = d[a] + d[b] - 2 * d[x];
		if (c >= dis) cout << b;
		else if (c <= d[a] - d[x]) cout << lift(a, c);
		else cout << lift(b, dis - c);
		cout << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	///freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	solve();
}