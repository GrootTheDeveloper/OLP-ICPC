#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 2e5 + 5;
pair <int,int> e[maxn];
vector <int> g[maxn];
int cycle = 0;
signed vs[maxn];

void dfs(int u)
{
	if (cycle) return;
	vs[u] = 1;
	for (int v : g[u])
	{
		if (!vs[v]) dfs(v);
		else if (vs[v] == 1) cycle = 1;
	}
	vs[u] = 2;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x,y; cin >> x >> y;
		e[i] = {x,y};
		g[x].push_back(y);
	}
	if (m == 0) return cout << 0,0;
	for (int i = 1; i <= n; i++)
		if (!vs[i]) dfs(i);
	cout << 1 + cycle << '\n';
	for (int i = 1; i <= m; i++)
		if (e[i].first < e[i].second) cout << "1\n";
		else cout << 1 + cycle << '\n';
}