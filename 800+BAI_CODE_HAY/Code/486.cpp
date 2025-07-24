#include <bits/stdc++.h>
using namespace std;


struct Segmentree
{
	vector <int> seg;
	vector <int> lazy;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
		lazy.assign(n * 4 + 5, -1);
	}
	void push_down(int id, int l, int r)
	{
		int mid = (l + r) >> 1;
		if (lazy[id] != -1)
		{
			seg[id * 2] = (mid - l + 1) * lazy[id];
			seg[id * 2 + 1] = (r - mid) * lazy[id];
			lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
			lazy[id] = -1;
		}
	}
	void Set(int id, int l, int r, int u, int v, const int &kind)
	{
		if (u > r || v < l) return;
		if (u <= l && r <= v)
		{
			seg[id] = (r - l + 1) * kind;
			lazy[id] = kind;
			return;
		}
		push_down(id, l, r);
		int mid = (l + r) >> 1;
		Set(id * 2, l, mid, u, v, kind);
		Set(id * 2 + 1, mid + 1, r, u, v, kind);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}	
	int Get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) / 2;
		push_down(id, l, r);
		return Get(id * 2, l, mid, u, v) 
			+ Get(id * 2 + 1, mid + 1, r, u, v);
	}
	
	int Get(int l, int r)
	{
		return Get(1, 1, n, l, r);
	}
	void Set(int l, int r, int kind)
	{
		Set(1, 1, n, l, r, kind);
	}
};
const int N = 1e5 + 5;
int face[N], leader_chain[N], par[N], pos[N], tin[N], tout[N], a[N], sz[N], d[N];
int timer, Cur_block, Cur_pos, n, q;
vector <int> g[100005];
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	{
		if (v == p) continue;
		d[v] = d[u] + 1;
		par[v] = u;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

void hld(int s, int p = 0)
{
	if (!face[Cur_block])
		face[Cur_block] = s;
	tin[s] = ++timer;
	leader_chain[s] = Cur_block;
	pos[s] = ++Cur_pos;
	a[Cur_pos] = s;

	int nxt = 0;
	for (int v : g[s])
		if (sz[v] > sz[nxt] && v != p) nxt = v;
	if (nxt) hld(nxt, s);
	for (int v : g[s])
	{
		if (v != nxt && v != p)
		{
			Cur_block++;
			hld(v, s);
		}
	}
	tout[s] = timer;


}
void _black(int u, Segmentree &st)
{
	int ans = 0;
	while (leader_chain[u] != leader_chain[1])
	{
		int l = pos[face[leader_chain[u]]], r = pos[u];
		ans += (r - l + 1) - st.Get(l, r);
		st.Set(l, r, 1);
		u = par[face[leader_chain[u]]];
	}
	ans += pos[u] - st.Get(1, pos[u]);
	st.Set(1, pos[u], 1);
	cout << ans << '\n';
}
void _white(int u, Segmentree &st)
{
	int ans = 0;
	ans += st.Get(pos[u], tout[u]);
	st.Set(pos[u], tout[u], 0);
	cout << ans << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	hld(1);
	Segmentree st(n);
	while (q--)
	{
		int kind, u; cin >> kind >> u;
		if (kind == 1)
			_black(u, st);
		else
			_white(u, st);
	}
}