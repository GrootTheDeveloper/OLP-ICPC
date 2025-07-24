#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first 
#define se second 
const int inf = 1e9 + 31 + 01 + 2007;
vector<ii> g[100005];
int d[3][100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		//g[v].emplace_back(u, w);
	}


	priority_queue<ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= n; i++)
		d[1][i] = d[2][i] = inf;
	d[1][1] = 0;
	q.push({0, 1});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int kc = top.fi, u = top.se;
		if (kc > d[1][u] && kc > d[2][u])
			continue;
		for (ii &x : g[u])
		{
			int v = x.fi, w = x.se;
			if (kc + w < d[1][v])
			{
				d[1][v] = kc + w;
				q.push({kc + w, v});
			} else if (kc + w > d[1][v] && kc + w < d[2][v])
			{
				d[2][v] = kc + w;
				q.push({kc + w, v});
			}
		}
	}
	cout << d[2][n];

}

