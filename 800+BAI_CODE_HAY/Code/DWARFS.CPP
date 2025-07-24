#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int inf = 1e7;
int n, num;
int seg[N * 4], tout[N], tin[N], lazy[N * 4], d[N];
vector<int> g[N];

void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void down(int id, int l, int r)
{
	if (lazy[id])
	{
		int val = lazy[id];
		seg[id * 2] += val;
		seg[id * 2 + 1] += val;
		lazy[id * 2] += val;
		lazy[id * 2 + 1] += val;
		lazy[id] = 0;
	}
}
void update_add(int id, int l, int r, int u, int v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update_add(id * 2, l, mid, u, v, val);
	update_add(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void dfs(int u, int p = 0)
{
	tin[u] = ++num;
	update(1, 1, n, tin[u], d[u]);
	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
	}
	tout[u] = num;
}
int ans;
void solve(int u, int step = 0, int p = 0)
{
	update_add(1, 1, n, tin[u], tout[u], -inf);
	if (seg[1] >= step)
		ans = max(ans, step);

	for (int v : g[u]) if (v != p)
		solve(v, step + 1, u);
	update_add(1, 1, n, tin[u], tout[u], inf);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int s, t; cin >> s >> t;
	dfs(s);
	solve(t);
	cout << ans + 1;
}