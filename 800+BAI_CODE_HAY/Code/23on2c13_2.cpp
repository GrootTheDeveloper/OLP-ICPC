#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 5;
const int inf = -1e15;

int nex[N], pos[N], top[N], sz[N], chain[N], face[N], a[N];
int cur_chain, cur_pos;
vector<int> g[N];
int n, q;
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

void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && l == pos)
		return seg[id] = {val, val, val, val}, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return {0, inf, 0, 0};
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
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
		nex[s] = p;
		top[s] = cur_pos + 1;
	}
	pos[s] = ++cur_pos;
	update(1, 1, n, cur_pos, a[s]);
	chain[s] = cur_chain;
	nex[s] = nex[face[cur_chain]];
	top[s] = top[face[cur_chain]];
	int nxt = 0;
	for (int v : g[s])
		if (sz[v] > sz[nxt] && v != p) nxt = v;
	if (nxt) hld(nxt, s);
	for (int v : g[s])
	if (v != nxt && v != p)
	{
		cur_chain++;
		hld(v, s);
	}
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
	if (pos[u] > pos[v])
	{
		node tmp = get(1, 1, n, pos[v], pos[u]);
		t1 = tmp + t1;
	}else
	{
		node tmp = get(1, 1, n, pos[u], pos[v]);
		t2 = tmp + t2;
	}
	swap(t1.suf, t1.pre);
	cout << max(0ll, (t1 + t2).ans) << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	hld(1);
	while (q--)
	{
		int u, v; cin >> u >> v;
		query(u, v);
	}
}