#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

vector<int> g[100005];
int d[100005];
bool mark[100005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	priority_queue<ii> q;
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= k; i++)
	{
		int ai, x; cin >> ai >> x;
		d[ai] = x;
		q.push({x, ai});
		mark[ai] = true;
	}
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, w = top.fi;
		if (w == 0 || w < d[u]) continue;
		for (int v : g[u])
		{
			if (d[v] < w - 1)
			{
				mark[v] = true;
				d[v] = w - 1;
				q.push({d[v], v});
			}
		}

	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += mark[i];
	cout << ans;
}