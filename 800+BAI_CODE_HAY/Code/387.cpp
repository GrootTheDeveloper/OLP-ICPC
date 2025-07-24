#include <bits/stdc++.h>
using namespace std; 
const int inf = -1e9;
const int N = 1e5 + 5;

int nex[N], face[N], pos[N], top[N], chain[N], sz[N], a[N];
int cur_chain, cur_pos;
int n, q;
vector<int> g[N];
struct node
{
	int ans, sum, pre, suf;
	node friend operator + (const node &a, const node &b)
	{
		if (a.sum == inf) return b;
		if (b.sum == inf) return a;
		return {max({a.ans, b.ans, a.suf + b.pre}), a.sum + b.sum, max(a.pre, a.sum + b.pre), max(b.suf, b.sum + a.suf)};
	}
};
node seg[N * 4];
int lazy[N * 4];
void update_node(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = {val, val, val, val}, void();
	int mid = (l + r) >> 1;
	update_node(id * 2, l, mid, pos, val);
	update_node(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void down(int id, int l, int r)
{
	if (lazy[id] != inf)
	{
		int mid = (l + r) >> 1, val = lazy[id];
		int x = val * (mid - l + 1), y = val * (r - mid);
		seg[id * 2] = (val < 0? (node){val, x, val, val} : (node){x, x, x, x});
		seg[id * 2 + 1] = (val < 0? (node){val, y, val, val} : (node){y, y, y, y});
		lazy[id * 2] = lazy[id * 2 + 1] = val;
		lazy[id] = inf;
	}
}
void update_set(int id, int l, int r, const int &u, const int &v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		lazy[id] = val;
		int x = val * (r - l + 1);
		seg[id] = (val < 0? (node){val, x, val, val} : (node){x, x, x, x});
		return;
	}
	int mid = (l + r) >> 1;
	down(id, l, r);
	update_set(id * 2, l, mid, u, v, val);
	update_set(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return {inf, inf, inf, inf};
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	node t1 = get(id * 2, l, mid, u, v);
	node t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return t1 + t2;
}
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	if (v != p)
		dfs(v, u), sz[u] += sz[v];
}
void hld(int s, int p = 0)
{
	if (!face[cur_chain])
	{
		face[cur_chain] = s;
		top[s] = cur_pos + 1;
		nex[s] = p;
	}
	pos[s] = ++cur_pos;
	update_node(1, 1, n, cur_pos, a[s]);
	chain[s] = cur_chain;
	nex[s] = nex[face[cur_chain]];
	top[s] = top[face[cur_chain]];
	int nxt = 0;
	for (int v : g[s])
	if (v != p && sz[v] > sz[nxt])
		nxt = v;
	if (nxt) hld(nxt, s);

	for (int v : g[s])
	if (v != p && v != nxt)
		cur_chain++, hld(v, s);
}

void query(int u, int v)
{
	node t1 = {inf, inf, inf, inf}, t2 = {inf, inf, inf, inf};
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v])
		{
			node tmp = get(1, 1, n, top[u], pos[u]);
			t1 = tmp + t1;
			u = nex[u];
		} else
		{
			node tmp = get(1, 1, n, top[v], pos[v]);
			t2 = tmp + t2;
			v = nex[v];
		}
	}
	node tmp = get(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v]));
	if (pos[u] > pos[v]) t1 = tmp + t1;
	else t2 = tmp + t2;
	swap(t1.pre, t1.suf);
	cout << max(0, (t1 + t2).ans) << '\n';
}

void Up(int u, int v, int val)
{
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v])
			swap(u, v);
		update_set(1, 1, n, top[v], pos[v], val);
		v = nex[v];
	}
	update_set(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v]), val);
}

void solve()
{
	while (q--)
	{
		int kind, u, v; cin >> kind >> u >> v;
		if (kind == 1) query(u, v);
		else
		{
			int x; cin >> x;
			Up(u, v, x);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("duc.inp","r",stdin);
	freopen("duc.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fill(lazy, lazy + n * 4 + 1, inf);
	dfs(1);
	hld(1);
	solve();
}