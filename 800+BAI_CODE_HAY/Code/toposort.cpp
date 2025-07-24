#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> topo;
vector <int> g[1001];
bool visited[100001];
int in[1001],n,m;
void dfs(int u)
{
	visited[u] = true;
	for (int v : g[u])
		if (!visited[v]) dfs(v);
	topo.push_back(u);
}

void kahn()
{
	queue <int> q;
	for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topo.push_back(u);
		for (int v : g[u])
		{
			in[v] --;
			if (in[v] == 0) q.push(v);
		}
	}

}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int x,y, i = 1; i <= m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		in[y] ++;
	}
	//for (int i = 1; i <= n; i++)
	//	if (!visited[i]) dfs(i);
	kahn();
	//reverse(topo.begin(),topo.end());
	for (int x : topo) cout << x << ' ';

}