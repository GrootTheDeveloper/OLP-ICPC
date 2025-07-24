#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 
#define fi first
#define se second
const int inf = 1e12;
vector <ii> g[100005];
int d[100005][19];
bool mark[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + k + 1, inf);
	for (int i = 0; i <= k; i++) d[1][i] = 0;
	mark[1] = true;
	queue <ii> q;
	q.push({1,0});
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
				d[v][0] = d[u][0] + w;
				for (int i = 1; i <= k; i++)
					d[v][i] = min(d[u][i] + w, d[u][i - 1]);
				q.push({v, u});	
			}
			else
			{
				bool msk = false;
				if (d[v][0] > d[u][0] + w) {d[v][0] = d[u][0] + w; msk = 1;}
				for (int i = 1; i <= k; i++)
				{
					int val = d[v][i];
					d[v][i] = min({d[v][i], d[u][i] + w, d[u][i - 1]});
					if (d[v][i] != val) msk = true;
				}
				if (msk) q.push({v, u});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i][k] << ' ';
	
}