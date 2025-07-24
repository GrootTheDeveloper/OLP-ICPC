#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[1005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		g[u].emplace_back(v, (v - u) * 5);
		g[v].emplace_back(u, (v - u) * 5 * 2);
	}
	vector <int> d(n + 1, inf);
	d[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push({0, 1});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, kc = top.fi;
		if (kc > d[u]) continue;
		for (auto x : g[u]) 
		{
			int v = x.fi, w = x.se;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	cout << d[n];
}