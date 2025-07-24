#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;

long long lazy[N * 4], seg[N * 4];
int face[N], chain[N], top[N], nex[N], pos[N], sz[N], cur_chain, cur_pos;
vector<int> g[N];
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

	chain[s] = cur_chain;
	pos[s] = ++cur_pos;
	top[s] = top[face[cur_chain]];
	nex[s] = nex[face[cur_chain]];

	int nxt = 0;
	for (int v : g[s])
	if (sz[v] > sz[nxt] && v != p) nxt = v;
	
	if (nxt) hld(nxt, s);
	for (int v : g[s])
	if (v != nxt && v != p)
		cur_chain++, hld(v, s);
}
void down(int id, int l, int r)
{
	if (lazy[id])
	{
		int mid = (l + r) >> 1;
		seg[id * 2] += (mid - l + 1) * lazy[id];
		seg[id * 2 + 1] += (r - mid) * lazy[id];
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}
void update(int id, int l, int r, int u, int v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v) 
	{
		seg[id] += (r - l + 1) * val;
		lazy[id] += val;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id *2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long get(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return 0;
	if (l == r && pos == l) return seg[id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	return get(id * 2, l, mid, pos) + get(id * 2 + 1, mid + 1, r, pos);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);  
	int n, q; cin >> n >> q;
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
		int u, v, w; cin >> u >> v >> w;
		while (chain[u] != chain[v])
		{
			if (chain[u] > chain[v]) swap(u, v);
			update(1, 1, n, top[v], pos[v], w);
			v = nex[v];
		}
		update(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v]), w);
	}
	for (int i = 1; i <= n; i++)
		cout << get(1, 1, n, pos[i]) << ' ';
}