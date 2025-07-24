#include <bits/stdc++.h>
using namespace std;
#define int long long 


vector <int> g[1001], tg[1001];
stack <int> q;
bool visited[1001];

void DTOPO(int u)
{
	visited[u] = true;
	for (int v : g[u])
		if (!visited[v]) DTOPO(v);
	q.push(u);
}
void DFS(int u)
{
	visited[u] = true;
	for (int v : tg[u])
		if (!visited[v]) DFS(v);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int u,v, i = 1; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		tg[v].push_back(u);
	}

	DTOPO(1);
	memset(visited, false, sizeof(visited));
	int res = 0;
	while (q.size())
	{
		int x = q.top();
		q.pop();
		if (visited[x] == false)
		{
			res++;
			DFS(x);
		}
	}
	cout << res;
}
