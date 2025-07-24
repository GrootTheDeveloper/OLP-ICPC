#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct DSU
{
	vector <int> par, sz;
	int scc;	
	DSU (int n)
	{
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++) 
		{
			par[i] = 0;
			sz[i]  = 0;
		}
		scc = 0;
	}
	void add(int u)
	{
		par[u] = u;
		sz[u] = 1;
		scc++;
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		scc--;
		if (sz[a] < sz[b]) swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
	}
};

bool mark[200005];
vector <int> g[200005];
bool ans[200005];
int b[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	DSU d(n);
	for (int i = n; i >= 1; i--)
	{
		d.add(b[i]);
		mark[b[i]] = true;
		for (int x : g[b[i]])
			if (mark[x]) d.Union(b[i], x);
		ans[i] = (d.scc == 1? true : false);
	}
	for (int i = 1; i <= n; i++)
		cout << (ans[i]? "YES":"NO") << '\n';

}