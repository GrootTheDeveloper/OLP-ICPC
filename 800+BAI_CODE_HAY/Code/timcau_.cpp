#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5 + 5;

vector <int> g[maxn];
int low[maxn], tin[maxn], timer, n, m;
vector <pair<int,int>> Br;
void dfs(int u, int par = -1)
{
	tin[u] = low[u] = ++timer;
	for (int v : g[u]) if(v != par)
	{
		if (tin[v]) low[u] = min(low[u], tin[v]);
		else
		{
			dfs(v, u);
			low[u] = min(low[u],low[v]);
			if (low[v] > tin[u]) Br.emplace_back(min(u,v),max(u,v));
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u,v; cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (tin[i] == 0) dfs(i);
	sort(Br.begin(), Br.end());
	for (auto it : Br) cout << it.first << ' ' << it.second << '\n';
}