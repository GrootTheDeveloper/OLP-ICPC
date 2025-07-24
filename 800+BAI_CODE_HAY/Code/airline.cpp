#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

vector <int> g[111];
int d[111][20];
bool mark[111], f[111][111][17];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, cost, change, s, t; cin >> n >> m >> cost >> change >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, k; cin >> u >> v >> k;
		for (int j = 1; j <= k; j++)
		{
			int xe; cin >> xe;
			f[u][v][xe] = f[v][u][xe] = true;
		}
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= 16; j++) d[i][j] = inf;
	for (int i = 1; i <= 16; i++) d[s][i] = 0;
	queue <pair<int,int>> q;
	q.push({s,0}); mark[s] = true;
	while (q.size())
	{
		auto top = q.front(); q.pop();
		int u = top.first, p = top.second;
		for (int v : g[u]) if (v != p)
		{

			if (mark[v] == false)
			{
				for (int old = 1; old <= 16; old ++)
					for (int New = 1; New <= 16; New++)
						if (f[u][v][New])
							d[v][New] = min(d[v][New], d[u][old] + cost + change * (old != New));
				q.push({v, u});
				mark[v] = true;
			} else
			{
				bool msk = false;
				for (int old = 1; old <= 16; old ++)
					for (int New = 1; New <= 16; New++)
						if (f[u][v][New])
						{
							if (d[v][New] > d[u][old] + cost + change * (old != New))
							{
								msk = true;
								d[v][New] = d[u][old] + cost + change * (old != New);
							}
						}
				if (msk) q.push({v,u});
			}
		}
	}
	int res = inf;
	for (int i = 1; i <= 16; i++) res = min(res, d[t][i]);
	cout << res;
	
}


