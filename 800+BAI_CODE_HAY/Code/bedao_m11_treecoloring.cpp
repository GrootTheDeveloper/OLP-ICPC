#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5 + 5;
int d[maxn];
vector <pair<int,int>> g[maxn];
int n;
void inp()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u,v,w; cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
}
void dfs(int u, int p = -1)
{
	for (auto x : g[u]) if (x.first != p)
	{
		int v = x.first;
		if (x.second & 1) d[v] = 1 - d[u];
		else d[v] = d[u];
		dfs(v,u);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	inp();
	dfs(1);
	for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}