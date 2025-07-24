#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define ii pair<int,int>
#define fi first
#define se second 
vector <ii> g[100005];
int up[100005][18], d[100005], flow[100005][18];

void dfs(int u, int p = 0, int w = 0)
{
	up[u][0] = p;
	flow[u][0] = w;
	for (int i = 1; i <= 17; i++) 
	{
		flow[u][i] = max(flow[u][i - 1], flow[up[u][i - 1]][i - 1]);
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (auto x : g[u]) if (x.fi != p)
	{
		int v = x.fi, w = x.se;
		d[v] = d[u] + 1;
		dfs(v, u, w);
	}
}
int lift(int v, int k)
{
	for (int i = 17; i >= 0; i--)
		if (k >> i & 1) v = up[v][i];
	return v; 
}
int MaxCost(int u, int v)
{
	if (d[u] > d[v]) swap(u,v);
	int res = -1;
	for (int i = 17; i >= 0; i--)
		if ((d[v] - d[u]) >> i & 1){
			res = max(res, flow[v][i]);
			v = up[v][i];
		}
	if (u == v) return res;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i])
		{
			res = max({flow[u][i], flow[v][i], res});
			u = up[u][i];
			v = up[v][i];
		}
	res = max({res, flow[u][0], flow[v][0]});
	return res;
	
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++) 
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	dfs(1);
	while (q--)
	{
		int u, v; cin >> u >> v;
		cout << MaxCost(u, v) << '\n';
	}
}
