#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
int d[111][111];
bool mark[111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
			if (d[i][j] == 0 && i != j) d[i][j] = inf;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
	int u = 1;
	mark[1] = true;
	int res = 0;
	while (true)
	{
		int cost = inf, v = -1;
		for (int i = 2; i < n; i++)
			if (!mark[i] && d[u][i] != inf)
			{
				if (d[u][i] < cost) v = i, cost = d[u][i];
				else if (d[u][i] == cost) v = min(v, i);
			}
		if (v != -1)
		{
			res += d[u][v];
			u = v;
			mark[u] = 1;
		} else break;
	}
	cout << res + d[u][n];
}