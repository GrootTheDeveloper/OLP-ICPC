#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first 
#define se second
int d[100005], cnt[100005], mark[100005], msk, par[100005], a[100005];
vector <int> g[100005];
ii eg[100005];
void dfs(int u, int p = 0)
{
	for (int id : g[u])
	{
		int v = eg[id].fi + eg[id].se - u;
		if (v == p) continue;
		d[v] = d[u] + 1;
		par[v] = id;
		dfs(v, u);
	}

}
void proc(int u, int v)
{
	while (u != v)
	{
		if (d[u] != d[v])
		{
			if (d[u] > d[v])
			{
				if (mark[par[u]] != msk)
				{
					cnt[par[u]]++;
					mark[par[u]] = msk;
				}
				u = eg[par[u]].fi + eg[par[u]].se - u;
			}
			else
			{
				if (mark[par[v]] != msk)
				{
					cnt[par[v]]++;
					mark[par[v]] = msk;
				}
				v = eg[par[v]].fi + eg[par[v]].se - v;
			}

		} else
		{
			if (mark[par[u]] != msk)
				{
					cnt[par[u]]++;
					mark[par[u]] = msk;
				}
			u = eg[par[u]].fi + eg[par[u]].se - u;
			if (mark[par[v]] != msk)
				{
					cnt[par[v]]++;
					mark[par[v]] = msk;
				}
			v = eg[par[v]].fi + eg[par[v]].se - v;
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		eg[i] = {u, v};
		g[u].push_back(i);
		g[v].push_back(i);
	}
	dfs(1);
	for (int l = 1; l <= m; l++)
	{
		msk = l;
		int x; cin >> x;
		for (int i = 1; i <= x; i++) cin >> a[i];
		for (int i = 2; i <= x; i++) proc(a[1], a[i]);
	}
	vector <int> vec;
	for (int i = 1; i < n; i++) if (cnt[i] >= k) vec.push_back(i);
	cout << vec.size() << '\n';
	for (int x : vec) cout << x << ' ';

}