#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[10005];
int tin[1005], low[1005], timer;
bool us[1005];
int n,m;
void dfs(int u, int p = -1)
{
	us[u] = true;
	low[u] = tin[u] = ++timer;
	for (int v : g[u])
	{
		if (v == p) continue;
		if (us[v]) low[u] = min(low[u], tin[v]);
		else 
		{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if (low[v] > tin[u]) cout << u << ' ' << v << '\n';
		}
	}

}
void find_bridge()
{
	cout << "List bridges :\n";
	for (int i = 1; i <= n; i++)
		if (!us[i]) dfs(i);
}

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

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inp();
	find_bridge();
	
}