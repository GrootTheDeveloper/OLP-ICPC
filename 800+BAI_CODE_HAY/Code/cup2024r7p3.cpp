#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TASK "COLTR"
const int N = 2e5 + 5;

int seg[N * 4], lazy[N * 4], sz[N], par[N];
int chain[N], face[N], pos[N], col[N], tout[N];
int cur_pos, cur_chain;
int n, q;
vector <int> g[N];

void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p)
	{
		par[v] = u;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void down(int id)
{
	if (lazy[id])
	{
		seg[id * 2] = 0ll | (1ll << lazy[id]);
		seg[id * 2 + 1] = 0ll | (1ll << lazy[id]);
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
		lazy[id] = 0;
	}
}
void update(int id, int l, int r, int u, int v, int val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		seg[id] = 0ll | (1ll << val);
		lazy[id] = val;
		return;
	}
	down(id);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] | seg[id * 2 + 1];
}
void Up(int l, int r, int val)
{
	update(1, 1, n, l, r, val);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	down(id);
	return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
}
int Get(int l, int r)
{
	return get(1, 1, n, l, r);
}
void hld(int s, int p = 0)
{
	if (!face[cur_chain])
		 face[cur_chain] = s;

	pos[s] = ++cur_pos;
	Up(cur_pos, cur_pos, col[s]);
	chain[s] = cur_chain;
	int nxt = 0;
	for (int v : g[s])
		if (sz[v] > sz[nxt] && v != p) nxt = v;
	if (nxt) hld(nxt, s);
	for (int v : g[s])
		if (v != p && v != nxt)
		{
			cur_chain++;
			hld(v, s);
		}
	tout[s] = cur_pos;
}

void solve()
{
	while (q--)
	{
		int kind, u, v, x;
		cin >> kind;
		///////////////////////////////////////////
		if (kind == 1)
		{
			cin >> u >> v >> x;
			while (chain[u] != chain[v])
			{
				if (chain[u] > chain[v]) swap(u, v);
				Up(pos[face[chain[v]]], pos[v], x);
				v = par[face[chain[v]]];
			}
			if (pos[u] > pos[v]) swap(u, v);
			Up(pos[u], pos[v], x);
		}
		////////////////////////////////////////////
		if (kind == 2)
		{
			cin >> u >> x;
			Up(pos[u], tout[u], x);
		}
		////////////////////////////////////////////
		if (kind == 3)
		{
			cin >> u >> v;
			int ans = 0;
			while (chain[u] != chain[v])
			{
				if (chain[u] > chain[v]) swap(u, v);
				ans |= Get(pos[face[chain[v]]], pos[v]);
				v = par[face[chain[v]]];
			}
			if (pos[u] > pos[v]) swap(u, v);
			ans |= Get(pos[u], pos[v]);
			cout << __builtin_popcountll(ans) << '\n';
		}
		/////////////////////////////////////////////
		if (kind == 4)
		{
			cin >> u;
			int ans = Get(pos[u], tout[u]);
			cout << __builtin_popcountll(ans) << '\n';
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen(TASK".INP","r",stdin);
	freopen(TASK".OUT","w",stdout);
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		cin >> col[i];
	dfs(1);	
	hld(1);
	solve();
}