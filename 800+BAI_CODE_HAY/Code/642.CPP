#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;
const long long INF = 1e15;
struct node
{
	long long low, cnt;
	node() : low(0), cnt(0) {};
	node(long long a, long long b) : low(a), cnt(b) {};

	node operator + (const node &other)
	{
		if (low != other.low)
			return (low < other.low? node(low, cnt) : other);
		return node(low, cnt + other.cnt);
	}
}seg[N * 4];
long long lazy[N * 4];
//////
int top[N], sz[N], pos[N], chain[N], nex[N], face[N];
int cur_chain, cur_pos, n, q;
vector<int> g[N];
////Segmentree
void down(int id, int l, int r)
{
	if (lazy[id])
	{
		long long tmp = lazy[id];
		seg[id * 2].low += tmp;
		seg[id * 2 + 1].low += tmp;
		lazy[id * 2] += tmp;
		lazy[id * 2 + 1] += tmp;
		lazy[id] = 0;
	}
}
void update(int id, int l, int r, int pos, long long val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = node(val, 1ll), void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update_add(int id, int l, int r, int u, int v, const long long &val)
{
	if (u > r || v < l)
		return;
	if (u <= l && r <= v)
	{
		seg[id].low += val;
		lazy[id] += val;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update_add(id * 2, l, mid, u, v, val);
	update_add(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l)
		return INF;
	if (u <= l && r <= v)
		return seg[id].low;
	int mid = (l + r) >> 1;
	down(id, l, r);
	return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
/////////////////////////////////////
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int &v : g[u]) if (v != p)
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
	chain[s] = cur_chain;
	update(1, 1, n, cur_pos, 0);
	top[s] = top[face[cur_chain]];
	nex[s] = nex[face[cur_chain]];

	int nxt = 0;
	for (int &v : g[s])
	if (v != p && sz[v] > sz[nxt]) 
		nxt = v;
	if (nxt) hld(nxt, s);

	for (int &v : g[s])
	if (v != nxt && v != p)
		++cur_chain, hld(v, s);
}
void add(int &u, int &v, long long k)
{
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v]) swap(u, v);
		update_add(1, 1, n, top[v], pos[v], k);
		v = nex[v];
	}
	if (pos[u] > pos[v]) swap(u, v);
	update_add(1, 1, n, pos[u], pos[v], k);	
}
long long lowest_heigh(int u, int v)
{
	long long ans = 1e15;
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v]) swap(u, v);
		ans = min(ans, get(1, 1, n, top[v], pos[v]));
		v = nex[v];
	}
	if (pos[u] > pos[v]) swap(u, v);
	return min(ans, get(1, 1, n, pos[u], pos[v]));
}

void del(int &u, int &v, long long k)
{
	k = min(k, lowest_heigh(u, v));
	add(u, v, -k);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1);
	hld(1);
	while (q--)
	{
		int type, u, v;
		long long k;
		cin >> type >> u >> v >> k;
		if (type == 1)
			add(u, v, k);
		else
			del(u, v, k);
		cout << n - (seg[1].low == 0ll? seg[1].cnt : 0) << '\n';
	}
}