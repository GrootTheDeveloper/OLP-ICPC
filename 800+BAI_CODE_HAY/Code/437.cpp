#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
const int INF = 791621423;

int d[100005][11];
vector<int> g[100005];

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
	memset(d, 0x2f, sizeof(d));
	priority_queue <iii, vector<iii>, greater<iii>> q;
	d[1][0] = 0;
	q.push({0,{1, 0}});
	while (q.size())
	{
		iii top = q.top(); q.pop();
		int u = top.se.fi, re = top.se.se, cur = top.fi;
		if (cur > d[u][re]) continue;
		int newCost = cur + (re == k - 1);
		for (int v : g[u])
		{
			if (d[v][(re + 1) % k] > newCost)
			{
				d[v][(re + 1) % k] = newCost;
				q.push({newCost, {v, (re + 1) % k}});
			}
		}
	}
	cout << (d[n][0] == INF? -1 : d[n][0]); 

}