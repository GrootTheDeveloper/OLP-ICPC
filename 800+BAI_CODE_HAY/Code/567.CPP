#include <bits/stdc++.h>
using namespace std;

int d[111][111];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		d[u][v] = d[v][u] = min(d[u][v], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int ans = 1e9;
	for (int u = 1; u <= n; u++)
	for (int v = u + 1; v <= n; v++)
	{
		int cur_res = 0;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			cur_res += min({d[i][j], d[i][u] + d[v][j], d[i][v] + d[u][j]});
		ans = min(ans, cur_res);
	}
	cout << ans;

}