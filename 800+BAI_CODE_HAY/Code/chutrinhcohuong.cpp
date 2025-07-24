#include <bits/stdc++.h>
using namespace std;
#define int long long 


int col[1001],in[1001];
vector <int> g[1001];
int par[1001],n,m;

bool dfs(int u)
{
	col[u] = 1;
	for (int v : g[u])
		if (col[v] == 0)
		{
			par[v] = u;
			if (dfs(v)) return true;
		}
		else if (col[v] == 1) return true;
	col[u] = 2;
	return false;
}
bool kahn()
{
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);
	vector <int> loc;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int v : g[u]) 
		{
			in[v] --;
			if (in[v] == 0) q.push(v);
		}
		loc.push_back(u);
	}
	return loc.size() == n;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1,x, y; i <= m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		in[y] ++;
	}
	/*for (int i = 1; i <= n; i++)
		if (col[i] == 0) 
		{
			if (dfs(i)) return cout << "YES",0;
		}
	cout << "NO";*/
	if (kahn()) cout << "NO"; else cout << "YES";
}