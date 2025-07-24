#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e6 + 5;
vector <int> g[maxn];
int d[maxn], dif;
int c[maxn];

void dfs(int u, int par = 1)
{
	for (int v : g[u]) if (v != par)
	{
		dif += (c[v] != c[u]);
		d[u] += (c[v] != c[u]);
		dfs(v,u);
	}
	d[u] += (c[u] != c[par]);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (dif == d[i])
		
	cout << "NO";
	
}