#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5 + 5;
int bit[N], lim;
int sz[N], d[N], l, r;
int n, root;
bool del[N];
vector <int> g[N];
void update(int idx, int val)
{
	for(;idx <= n; idx += (idx&(-idx))) bit[idx] += val;
}
int get(int l, int r)
{
	int ans = 0;
	l--;
	for (;r > 0; r -= (r&(-r))) ans += bit[r];
	for (;l > 0; l -= (l&(-l))) ans -= bit[l];
	return ans;
}

void calc_size(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
		if (!del[v] && v != p)
		{
			calc_size(v, u);
			sz[u] += sz[v];
		}
} 
int get_cen(int u, int p, int n)
{
	for (int v : g[u])
		if (!del[v] && v != p && sz[v] > n / 2) return get_cen(v, u, n);
	return u;
}

void down(int u, int p)
{
	if (d[u] > r) return;
	update(d[u], 1);
	for (int v : g[u])
		if (!del[v] && v != p) down(v, u);
}
void dfs(int u, int p, ll &ans)
{
	for (int v : g[u])
	{
		if (v == p || del[v]) continue;
		//cout << v << ' ';
		d[v] = d[u] + 1;
		if (d[v] <= r)
		{
			lim = max(lim, d[v]);
			ans += (ll)get(max(0, l - d[v]), r - d[v]);
			ans += (ll)(d[v] >= l && d[v] <= r);
			dfs(v, u, ans);
		}
		if (u == root) down(v, u);
	}
}
ll solve(int u)
{
	ll ans = 0;
	calc_size(u);
	root = get_cen(u, 0, sz[u]);
	lim = 0;
	d[root] = 0;
	dfs(root, 0, ans);
	del[root] = true;
	for (int i = 1; i <= lim; i++) update(i, -get(i, i));
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
