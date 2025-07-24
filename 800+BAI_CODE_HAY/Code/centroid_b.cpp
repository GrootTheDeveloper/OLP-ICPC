#include <bits/stdc++.h>
using namespace std;
#define ll long long  
int n, k;
int d[200005], sz[200005];
int root;
bool del[200005];
int l, r;
vector <int> g[200005];
int bit[200005], lim;

	void update(int idx, int val)
	{
		while (idx <= n)
		{
			bit[idx] += val;
			idx += (idx & (-idx));
		}
	}
	int sum(int idx)
	{
		int ans = 0;
		while (idx > 0)
		{
			ans += bit[idx];
			idx -= (idx & (-idx));
		}
		return ans;
	}
	int get(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}

void calc_size(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	{
		if (v == p || del[v]) continue;
		d[v] = d[u] + 1;
		calc_size(v, u);
		sz[u] += sz[v];
	}
}
int get(int u, int p, int n)
{
	for (int v : g[u])
		if (v != p && !del[v] && sz[v] > n / 2) return get(v, u, n);
	return u;
}
void down(int u, int p)
{
	if (d[u] > r) return;
	update(d[u], 1);
	for (int v : g[u])
		if (v != p && !del[v]) down(v, u);
}
void dfs(int u, int p, ll &ans)
{
	for (int v : g[u])
	{
		if (v == p || del[v]) continue;
		d[v] = d[u] + 1;
		lim = max(lim, d[v]);
		if (d[v] <= r)
		{
			ans += (ll)get(max(0, l - d[v]), r - d[v]);
			ans += (ll)(d[v] >= l && d[v] <= r);
			dfs(v, u, ans);
		}
		if (u == root)
			down(v, u);
	}
}
ll solve(int u)
{
	ll ans = 0;
	calc_size(u);
	root = get(u, 0, sz[u]);
	d[root] = 0;
	lim = 0;
	dfs(root, 0, ans);
	for (int i = 1; i <= lim; i++) update(i, -get(i, i));
	del[root] = true;
	for (int v : g[root])
		if (!del[v]) ans += solve(v);
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << solve(1);
}
