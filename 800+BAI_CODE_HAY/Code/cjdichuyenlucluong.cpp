#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second

struct DSU
{
	vector <int> par, sz;
	DSU (int n)
	{
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			par[i] = i;
			sz[i]  = 1;
		}
	}
	int find(int v)
	{
		return (v == par[v]? v : par[v] = find(par[v]));
	}
	void Union(int a, int b)
	{
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
	}
	bool check(int u, int v)
	{
		v = find(v); u = find(u);
		return u == v;
	}
};

iii eg[200005];
vector <int> g[1000005];
int par[100005];
bool vs[100005];
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	vs[s] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : g[u]) if (!vs[v])
		{
			par[v] = u;
			vs[v]  = true;
			q.push(v);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,s,t; cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
		cin >> eg[i].se.fi >> eg[i].se.se >> eg[i].fi;
	sort(eg + 1, eg + m + 1, greater<iii>());
	
	DSU d(n);
	int res;
	for (int i = 1; i <= m; i++)
	{
		if (d.check(s,t)) break;
		int u = eg[i].se.fi, v = eg[i].se.se, w = eg[i].fi;
		res = w;
		d.Union(u,v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(s);
	vector <int> vec;
	for (int u = t; u != 0; u = par[u]) vec.push_back(u);
	reverse(vec.begin(), end(vec));
	cout << res << '\n';
	for (int x : vec) cout << x << ' ';

}