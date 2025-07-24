#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> g[1001];
bool visited[1001];
int d[1001];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("bfs.inp","r",stdin);
	freopen("bfs.out","w",stdout);
	int n,m; cin >> n >> m;
	for (int x,y,i = 1; i <= m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue <int> q;
	q.push(1);
	visited[1] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : g[u]) 
			if (visited[v] == false)
			{
				d[v] = d[u] + 1;
				visited[v] = true;
				q.push(v);
			}
	}
	for (int i = 2; i <= n; i++)
		cout << ((d[i])? d[i] : -1) << '\n';
}