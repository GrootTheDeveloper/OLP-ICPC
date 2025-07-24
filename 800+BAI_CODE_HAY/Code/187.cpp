#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector<ii> g[100005];
queue <int>  q[55];
int d[55][100005];
int a[100005];
void dijkstra(int x)
{
	while (q[x].size())
	{
		int u = q[x].front(); q[x].pop();
		for (ii c : g[u])
		{
			int v = c.fi, w = c.se;
			if (d[x][v] > d[x][u] + w)
			{
				d[x][v] = d[x][u] + w;
				q[x].push(v);
			}

		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) 
		for (int j = 1; j <= n; j++) d[i][j] = inf;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		q[a[i]].push(i);
		d[a[i]][i] = 0;
	}
	for (int i = 1; i <= m; i++) 
	{
		int u,v,w; cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	for (int i = 1; i <= k; i++)
		dijkstra(i);
	
	
	int res = inf, pos = 0;
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int x = 1; x <= k; x++)
			ans += d[x][i];
		if (res > ans) res = ans, pos = i;
	}
	cout  << pos;
}