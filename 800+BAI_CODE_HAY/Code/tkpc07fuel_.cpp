#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e15;
int d[303][303], cost[303][303];


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, l; cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) 
	{
		fill(d[i], d[i] + n + 1, inf);
		fill(cost[i], cost[i] + n + 1, 1000000);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		d[u][v] = d[v][u] = w;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (d[i][j] <= l) cost[i][j] = 1;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	int q; cin >> q;
	while (q--)
	{
		int u, v; cin >> u >> v;
		cout << (cost[u][v] == 1000000? -1 : cost[u][v] - 1 )<< '\n';
	}
}