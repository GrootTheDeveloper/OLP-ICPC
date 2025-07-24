#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = -1e15;
const int N = 2e5 + 5;
int pos[N], nex[N], sz[N], chain[N], face[N], top[N];
int cur_chain, cur_pos;
vector <int> g[N];
int n, q, a[N];
struct node
{
	int sum, ans, pre, suf;
	node friend operator + (node a, node b)
	{
		if (a.sum == INF) return b;
		if (b.sum == INF) return a;
		return {a.sum + b.sum, max({a.ans, b.ans, a.suf + b.pre}), max(a.pre, a.sum + b.pre), max(b.suf, b.sum + a.suf)};
	}
}seg[N * 4];



void init(int id, int l, int r)
{
	if (l == r) return seg[id] = (node){INF, INF, INF, INF}, void();
	int mid = (l + r) >> 1;
	init(id * 2, l, mid);
	init(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id] = {val, val, val, val};
		return;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l)
		return {INF, 0, 0, 0};
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	node t1 = get(id * 2, l, mid, u, v);
	node t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return t1 + t2;
}

void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p)
	{
        dfs(v, u);
		sz[u] += sz[v];
	}
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
	update(1, 1, n, cur_pos, a[s]);
	chain[s] = cur_chain;
	top[s] = top[face[cur_chain]];
	nex[s] = nex[face[cur_chain]];

	int nxt = 0;
	for (int v : g[s])
		if (v != p && sz[v] > sz[nxt]) nxt = v;

	if (nxt) hld(nxt, s);

	for (int v : g[s])
		if (v != nxt && v != p)
			cur_chain++, hld(v, s);
}

void Query(int u, int v)
{
	node t1 = (node){INF, 0, 0, 0}, t2 = t1;
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v])
		{
			node tmp = get(1, 1, n, top[u], pos[u]);
			swap(tmp.pre, tmp.suf);
			t1 = t1 + tmp;
			u = nex[u];
		} else
		{
			t2 = get(1, 1, n, top[v], pos[v]) + t2;
			v = nex[v];
		}
	}
	if (pos[u] < pos[v])
		t2 = get(1, 1, n, pos[u], pos[v]) + t2;
	else
	{
		node tmp = get(1, 1, n, pos[v], pos[u]);
		swap(tmp.suf, tmp.pre);
		t1 = t1 + tmp;
	}
	cout << max((t1 + t2).ans, 0ll) << '\n';
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
		Query(u, v);
	}
}
