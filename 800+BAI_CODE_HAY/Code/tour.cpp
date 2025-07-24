#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
const int inf = 1e15;

vector <iii> g[1005];
int d[1005][1005];
int n, m, p, s, t;

void solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= p; j++) d[i][j] = inf;
	d[s][0] = 0;
	priority_queue <iii, vector<iii>, greater<iii>> q;
	q.push({0,{s,0}});
	while (q.size())
	{
		auto top = q.top(); q.pop();
		int u = top.se.fi, cost = top.se.se, kc = top.fi;
		if (kc > d[u][cost]) continue;
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se.fi, mon = x.se.se;
			if (cost + mon > p) continue;
			if (d[v][cost + mon] > d[u][cost] + w)
			{
				d[v][cost + mon] = d[u][cost] + w;
				q.push({d[v][cost + mon],{v, cost + mon}});
			}
		}
	}
	int res = inf;
	for (int i = 0; i <= p; i++) res = min(res, d[t][i]);
	if (res == inf) res = -1;
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	cin >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, x, y; cin >> u >> v >> x >> y;
		g[u].push_back({v, {x,y}});
		g[v].push_back({u, {x,y}});
	}
	solve();
}