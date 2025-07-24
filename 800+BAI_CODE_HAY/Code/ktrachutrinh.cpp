#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[1001];

bool visited[1001];

int par[1001];

int sta,en;
bool dfs(int u)
{
	visited[u] = true;
	for (int v : g[u])
	{
		if (!visited[v])
		{
			par[v] = u;
			if (dfs(v)) return true;
		}
		else if (v != par[u]) 
		{
			sta = v; en = u;
			return true;
		}
	}
	return false;
}

bool bfs(int u)
{
	visited[u] = true;
	queue <int> q;
	q.push(u);
	while (q.size())
	{
		int v = q.front();
		q.pop();
		for (int x : g[v])
			if (!visited[x]) par[x] = v, visited[x] = true, q.push(x);
			else if (x != par[v]) 
			{
				sta = v;
				en = x;
				return true;
			}
	}
	return false;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int x,y,i = 1; i <= m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) 
		{
			if (bfs(i)) 
			{
				cout << "yes" << '\n';
				/*vector <int> cycle; cycle.push_back(sta);
				while (en != sta)
				{
					cycle.push_back(en);
					en = par[en];
					//cout << en << ' ';
				}
				cycle.push_back(sta);
				reverse(cycle.begin(),cycle.end());
				for (int x : cycle) cout << x << ' ';
					cout << "\n";
				*/
				return 0;
			}
		}
	cout << "NO";
}