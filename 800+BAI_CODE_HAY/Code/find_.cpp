#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[1000];
bool visited[1000];
int par[1000];
void dfs(int u)
{
	visited[u] = true;
	for (int v : g[u])
		if (!visited[v])
		{
			par[v] = u;
			dfs(v);
		}
}
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int v : g[u]) 
			if (!visited[v]) q.push(v), par[v] = u, visited[v] = true;
	}
}
void find_path(int s, int t)
{
	//dfs(s);
	bfs(s);
	if (!visited[t]) return cout << -1,void();
	int x = t;
	vector <int> v;
	while (x)
	{
		v.push_back(x);
		x = par[x];
	}
	reverse(v.begin(),v.end());
	for (int c : v) cout << c << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		//g[y].push_back(x);
	}
	int s,t; cin >> s >> t;
	find_path(s,t);
}