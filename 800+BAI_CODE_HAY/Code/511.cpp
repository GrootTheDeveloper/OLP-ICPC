#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 5;

int chain[N], face[N], pos[N], tout[N], par[N], d[N], sz[N];
int cur_chain, cur_pos;
vector <int> g[N];
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p)
	{
		par[v] = u;
		d[v] = d[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
	int seg[N * 4], val[N];
	int n, q;
	void update(int id, int l, int r, int pos, const int &valu)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l) return seg[id] = valu, void();
		//down(id, l, r);
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos, valu);
		update(id * 2 + 1, mid + 1, r, pos, valu);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) >> 1;
		//down(id, l, r);
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	
	int Get(int l, int r)
	{
		return get(1, 1, n, l, r);
	}
	void Update(int r, int valu)
	{
		update(1, 1, n, r, valu);
	}


void hld(int s, int p = 0)
{
	if (!face[cur_chain])
		face[cur_chain] = s;
	pos[s] = ++cur_pos;
	Update(cur_pos, val[s]);
	chain[s] = cur_chain;
	int nxt = 0;
	for (int v : g[s])
		if (d[v] > d[nxt] && v != p) nxt = v;
	if (nxt) hld(nxt, s);
	for (int v : g[s])
		if (v != p && v != nxt)
			cur_chain++, hld(v, s);
	tout[s] = cur_pos;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> val[i];
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
		int kind, u, v;
		cin >> kind >> u;
		if (kind == 1)
			{
				cin >> v;
				Update(pos[u], v);
			}
		if (kind == 2)
			cout << Get(pos[u], tout[u]) << '\n';
	}
}