#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct DSU
{
	vector <int> par, sz;
	DSU (int n)
	{
		par.resize(n + 5); sz.resize(n + 5);
		for (int i = 1; i <= n; i++) 
			par[i] = i, sz[i] = 1;
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void unite(int a, int b)
	{
		 a = find(a); b = find(b);
		 if (a == b) return;
		 if (sz[a] < sz[b]) swap(a, b);
		 par[b] = a;
		 sz[a] += sz[b];
	}
	bool check(int a, int b) { return find(a) == find(b);}
};
struct node
{
	int u, v, w;
	bool operator<(const node &other)
	{
		return w > other.w;
	}
}eg[200005];

int par[100005];
vector <int> g[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg[i] = {u, v, w};
	}
	sort(eg + 1, eg + m + 1);
	DSU d(n);
	int ans = 0;
	for (int i = 1; i <= m && d.check(s, t) == false; i++)
		d.unite(eg[i].u, eg[i].v), ans = eg[i].w, g[eg[i].u].push_back(eg[i].v), g[eg[i].v].push_back(eg[i].u);
	cout << ans << '\n';
	queue <int> q;
	q.push(s);
	vector <bool> vs(n + 1, false);
	vs[s] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : g[u])
		{
			if (!vs[v])
			{
				vs[v] = true;
				par[v] = u;
				q.push(v);
			}
		}
	}
	vector <int> path;
	for (int u = t; u != 0; u = par[u]) path.push_back(u);
	reverse(begin(path), end(path));
	for (int x  : path) cout << x << ' ';

}