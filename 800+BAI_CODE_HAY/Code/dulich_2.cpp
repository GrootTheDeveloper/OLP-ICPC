#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;

vector <ii> g[1005];
int n, m, k;
int d[1005][505][2];
bool mark[1005];
void solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) d[i][j][1] = d[i][j][0] = inf;
	for (int i = 0; i <= k; i++) d[1][i][1] = d[1][i][0] = 0;
	mark[1] = true;
	queue <ii> q;
	q.push({1, 0});
	while (q.size())
	{
		ii top = q.front(); q.pop();
		int u = top.fi, p = top.se;
		for (auto x : g[u]) if (x.fi != p)
		{
			int v = x.fi, w = x.se;
			if (!mark[v])
			{
				mark[v] = true;
				d[v][0][0] = d[u][0][0] + w;
				for (int i = 1; i <= k; i++)
				{
					d[v][i][0] = min(d[u][i][0] + w, d[u][i][1] + w);
					d[v][i][1] = d[u][i - 1][0] + (w >> 1);
				}
				q.push({v, u});
			}
			else
			{
				bool msk = false;
				if (d[v][0][0] > d[u][0][0] + w) {msk = 1; d[v][0][0] = d[u][0][0] + w;}
				for (int i = 1; i <= k; i++)
				{
					int val0 = d[v][i][0], val1 = d[v][i][1];
					d[v][i][0] = min(d[v][i][0], min(d[u][i][0], d[u][i][1]) + w);
					d[v][i][1] = min(d[v][i][1], d[u][i - 1][0] + (w >> 1));
					if (val0 != d[v][i][0] || val1 != d[v][i][1] ) msk = 1; 
				}
				if (msk) q.push({v,u});
			}
		}
	}
	int res = min(d[n][k][0], d[n][k][1]);
	if (res == inf) res = -1;
	cout << res;

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		//g[v].emplace_back(u, w);
	}
	solve();
}