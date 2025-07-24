#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
int mark[5005];
int n, m;
int d[5005], c[5005];
vector<int> g[5005];
vector<ii> newg[5005];
void BFS(int s)
{
	queue<int> q;
	q.push(s);
	vector<int> D(n + 1, 10000);
	D[s] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : g[u])
		{
			if (D[v] != 10000) continue;
			D[v] = D[u] + 1;
			if (D[v] != d[s]) 
				q.push(v);
		}
	}

	for (int i = 1; i <= n; i++)
	if (i != s && D[i] <= d[s])
		newg[s].emplace_back(i, c[s]);
}

void dijkstra()
{
	vector<int> D(n + 1, inf);
	priority_queue<ii, vector<ii>, greater<ii>> q;
	D[1] = 0;
	q.push(make_pair(0,1));
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, cur = top.fi;
		if (D[u] < cur) continue;
		for (ii tmp : newg[u])
		{
			int v = tmp.fi, cost = tmp.se;
			if (D[v] > cur + cost)
			{
				D[v] = cur + cost;
				q.push(make_pair(D[v], v));
			}
		}
	}
	cout << D[n];
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i] >> d[i];

	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		BFS(i);
	dijkstra();
}