#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
int lan(int x,int  i) {
	return x / i + (x % i != 0);
}
void solve()
{
	int n, m, c; cin >> n >> m >> c;
	vector <int> d(n + 1, inf);
	vector <ii> g[n + 5];
	vector <bool> mark(n + 1, false);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	d[n] = 0;
	mark[n] = true;
	queue <ii> q;
	q.push({n, 0});
	while (q.size()) 
	{
		ii top = q.front(); q.pop();
		int u = top.fi, p = top.se;
		for (auto x : g[u]) if (x.fi != p)
		{
			int v = x.fi, w = x.se, cost = c - w;
			if (d[u] + w <= c && d[v] > d[u] + w)
				d[v] = d[u] + w, q.push({v,u});
			else
			{
				int s = d[u] - cost;
				int cnt = lan(s, c - 2 * w);
				if (d[v] > d[u] + (2 * cnt + 1) * w)
					d[v] = d[u] + (2 * cnt + 1) * w, q.push({v,u});
			}
			
		}
	}
	cout << d[1] << '\n';
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}