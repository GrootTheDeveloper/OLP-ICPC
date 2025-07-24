#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 5;
int cost1[N], cost2[N];
int pos[N], pos_lead[N], chain[N], face[N], nex[N], sz[N];
int seg[N * 4], lazy[N * 4];
int cur_chain, cur_pos, n;
struct node
{
	int u, v, c1, c2;
}eg[N];
vector <int> g[N];
void dfs(int u, int p = 0, int c1 = 0, int c2 = 0)
{
	sz[u] = 1;
	cost1[u] = c1, cost2[u] = c2;
	for (int id : g[u])
	{
		int v = eg[id].u + eg[id].v - u, c1 = eg[id].c1, c2 = eg[id].c2;
		if (v == p) continue;
		dfs(v, u, c1, c2);
		sz[u] += sz[v];
	}
}
void hld(int s, int p = 0)
{
	if (!face[cur_chain])
	{
		face[cur_chain] = s;
		pos_lead[s] = cur_pos + 1;
		nex[s] = p;
	}	
	pos[s] = ++cur_pos;
	pos_lead[s] = pos_lead[face[cur_chain]];
	chain[s] = cur_chain;
	nex[s] = nex[face[cur_chain]];
	int nxt = 0;
	for (int id : g[s])
	{
		int v = eg[id].u + eg[id].v - s;
		if (v != p && sz[v] > sz[nxt]) nxt = v;
	}
	if (nxt) hld(nxt, s);
	for (int id : g[s])
	{
		int v = eg[id].u + eg[id].v - s;
		if (v != p && v != nxt)
		{
			cur_chain++;
			hld(v, s);
		}
	}

}
void down(int id, int l, int r)
{
	if (lazy[id])
	{
		int temp = lazy[id], mid = (l + r) >> 1;
		seg[id * 2] += (mid - l + 1) * temp;
		seg[id * 2 + 1] += (r - mid) * temp;
		lazy[id * 2] += temp, lazy[id * 2 + 1] += temp;
		lazy[id] = 0;
	}
}
void update(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		seg[id] += (r - l + 1);
		lazy[id] += 1;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v);
	update(id * 2 + 1, mid + 1, r, u, v);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int get(int id, int l, int r , int pos)
{
	if (pos > r || pos < l) return 0;
	if (l == r && pos == l) return seg[id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	return get(id * 2, l, mid, pos) + get(id * 2 + 1, mid + 1, r, pos);
}

void add(int u, int v)
{
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v]) swap(u, v);
		update(1, 1, n, pos_lead[v], pos[v]);
		v = nex[v];
	}
	if (v == u) return;
	if (pos[u] > pos[v]) swap(u, v);
	update(1, 1, n, pos[u] + 1, pos[v]);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, c1, c2; cin >> u >> v >> c1 >> c2;
		eg[i].u = u, eg[i].v = v, eg[i].c1 = c1, eg[i].c2 = c2;
		g[u].push_back(i);
		g[v].push_back(i);
	}
	dfs(1);
	hld(1);
	for (int i = 2; i <= n; i++)
		add(i - 1, i);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = get(1, 1, n, pos[i]);
		ans += min(cost1[i] * cnt, cost2[i]);
	}
	cout << ans;

}




