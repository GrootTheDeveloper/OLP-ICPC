#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second

iii eg[100005];
vector <int> g[100005];
int par[100005], n, m;
bool us[100005];
void solve()
{
	us[1] = true;
	queue <int> q;
	q.push(1);
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int id : g[u])
		{
			int v = eg[id].se.fi + eg[id].se.se - u;
			if (us[v]) continue;
			us[v] = true;
			par[v] = id;
			if (v > n) return cout << v, void();
			q.push(v); 
		}
	}

	vector <int> v;
	for (int u = n; u != 1; u = eg[par[u]].se.se + eg[par[u]].se.fi - u)
	{
		v.push_back(eg[par[u]].fi);
	}
	reverse(begin(v), end(v));
	cout << v.size() << '\n';
	for (int x : v) cout << x << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg[i] = {w,{u, v}};
		g[u].push_back(i);
		g[v].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end(), [](int a, int b)
			{
				return eg[a].fi < eg[b].fi;
			});
	solve();
}