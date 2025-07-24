#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[100005];
int d[101][10004], p[101], c[101];
int n, m, k, l;
void dijkstra(int pos)
{
	for (int i = 1; i <= n; i++) d[pos][i] = inf;
	d[pos][p[pos]] = 0;
	priority_queue <ii, vector<ii>, greater<ii>> q;
	q.push({0, p[pos]});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, kc = top.fi;
		if (kc > d[pos][u]) continue;
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[pos][v] > d[pos][u] + w)
			{
				d[pos][v] = d[pos][u] + w;
				q.push({d[pos][v], v});
			}
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	for (int i = 1; i <= k; i++) cin >> p[i] >> c[i];
	for (int i = 1; i <= k; i++) dijkstra(i);
	while (l--)
	{
		int u, v; cin >> u >> v;
		int res = inf;
		for (int i = 1; i <= k; i++)
			res = min(res, d[i][u] + d[i][v] + c[i]);
		if (res == inf) res = -1;
		cout << res << '\n';
	}
}