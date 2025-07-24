#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
vector <int> g[1005];
int cl[1005];


bool bfs(int u)
{
	if (cl[u] != -1) return true;
	queue <int> q;
	q.push(u);
	cl[u] = 0;
	while (q.size())
	{
		int x = q.front(); q.pop();
		for (int v : g[x])
			if (cl[v] == -1)
			{
				q.push(v);
				cl[v] = 1 - cl[x];
			} 
			else if (cl[v] == cl[x]) return false;
	}
	return true;
}

void checker()
{
	for (int i = 1; i <= n; i++)
		if (!bfs(i)) return cout << "NO", void();
	cout << "YES";
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	checker();
}