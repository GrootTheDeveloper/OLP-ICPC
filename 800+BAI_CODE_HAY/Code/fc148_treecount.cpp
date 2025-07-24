#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int seg[N * 4], ans[N];
int tin[N], tout[N], pos;
int a[N], b[N];
vector <int> g[N];
void dfs(int u, int p = 0)
{
	tin[u] = ++pos;
	for (int v : g[u])
	{
		if (v == p) continue;
		dfs(v, u);
	}
	tout[u] = pos;
}

void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id] = 1, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
	{
		int v; cin >> v;
		g[v].push_back(i);
		g[i].push_back(v);
	}
	iota(b + 1, b + n + 1, 1);
	sort(b + 1, b + n + 1, [](int x, int y){return a[x] > a[y];});
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		ans[b[i]] = get(1, 1, n, tin[b[i]], tout[b[i]]);
		update(1, 1, n, tin[b[i]]);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

}