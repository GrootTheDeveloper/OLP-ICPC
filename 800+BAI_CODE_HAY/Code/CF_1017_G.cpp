#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 105, inf = -1e9;

struct node
{
    int sum, suf;
    node friend operator + (node a, node b)
    {
        if (a.sum == inf) return b;
        if (b.sum == inf) return a;
        return (node){a.sum + b.sum, max(b.suf, a.suf + b.sum)};
    }
}seg[N * 4];
bool lazy[N * 4];
int sz[N], nex[N], face[N], top[N], pos[N], chain[N], tout[N];
int cur_chain, cur_pos;
int n, q;
vector <int> g[N];
void dfs(int u)
{
	sz[u] = 1;
	for (int v : g[u])
	{
		dfs(v);
		sz[u] += sz[v];
	}
}
void down(int id, int l, int r)
{
    if (lazy[id])
    {
        int mid = (l + r) >> 1;
        seg[id * 2].sum = -(mid - l + 1);
        seg[id * 2 + 1].sum = -(r - mid);
        seg[id * 2].suf = seg[id * 2 + 1].suf = -1;
        lazy[id * 2] = lazy[id * 2 + 1] = true;
        lazy[id] = false;
    }
}
void update_node(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        seg[id].sum += val;
        seg[id].suf += val;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update_node(id * 2, l, mid, pos, val);
    update_node(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update_range(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id].sum = -(r - l + 1);
        seg[id].suf = -1;
        lazy[id] = true;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update_range(id * 2, l, mid, u, v);
    update_range(id * 2 + 1, mid + 1, r, u, v);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
node get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return (node){inf, inf};
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    node t1 = get(id * 2, l, mid, u, v);
    node t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return (node)(t1 + t2);
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
	update_node(1, 1, n, cur_pos, -1);
	chain[s] = cur_chain;
	top[s] = top[face[cur_chain]];
	nex[s] = nex[face[cur_chain]];
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt]) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != nxt)
        {
            cur_chain++;
            hld(v, s);
        }
    tout[s] = cur_pos;
}
node Get(int u)
{
    node tmp = (node){0, inf};
    while (chain[u] != chain[1])
    {
        node t = get(1, 1, n, top[u], pos[u]);
        tmp = (node)(t + tmp);
        u = nex[u];
    }
    node t = get(1, 1, n, top[u], pos[u]);
    tmp = (node)(t + tmp);
    return tmp;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int v = 2; v <= n; v++)
	{
		int u; cin >> u;
		g[u].push_back(v);
	}
	dfs(1);
	hld(1);
	while (q--)
    {
        int kind, u; cin >> kind >> u;
        if (kind == 1) update_node(1, 1, n, pos[u], 1);
        if (kind == 2)
        {
            update_range(1, 1, n, pos[u], tout[u]);
            int suf = Get(u).suf;
            if (suf >= 0) update_node(1, 1, n, pos[u], -(suf + 1));
        }
        if (kind == 3)
        {
            int suf = Get(u).suf;
            if (suf >= 0) cout << "black"; else cout << "white";
            cout << '\n';
        }
    }

}
