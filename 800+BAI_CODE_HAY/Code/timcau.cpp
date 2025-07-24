#include <bits/stdc++.h>
using namespace std;
#define int long long 

int timer, tin[1005], low[1005], n, m;
vector<int> g[1005];
bool vs[1005];

void inp()
{
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
	{	
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int u, int p = -1)
{
	if (vs[u]) return;
	vs[u] = true;
	tin[u] = low[u] = ++timer;
	for (int v : g[u])
	{
		if (v == p) continue;
		if (vs[v]) low[u] = min(low[u], tin[v]);
		else
		{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) cout << u << ' ' << v << '\n';
		}
	}
}

void find_bridge()
{
	cout << "Bridge is :\n";
	for (int i = 1; i <= n; i++)
		dfs(i);
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inp();
	find_bridge();	
}