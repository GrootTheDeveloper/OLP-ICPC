#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 31 + 01 + 2007;
const int lim = -1e4 - 10;
const int inf = -1e9;

struct node
{
	int ans, sum, pre, suf;
	node() : ans(0), sum(0), pre(0), suf(0){};

	node(int a, int b, int c, int d) : ans(a), sum(b), pre(c), suf(d) {};
	node operator + (const node &other)
	{
		return node(max({ans, other.ans, suf + other.pre}), sum + other.sum, max(pre, sum + other.pre), max(other.suf, suf + other.sum));
	}
}seg[N * 4];


int n, q;
int chain[N], pos[N], nex[N], sz[N], face[N], top[N], cur_chain, cur_pos, lazy[N * 4], a[N];
vector<int> g[N];
void update_node(int id, int l, int r, int pos, const int &val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id] = node(val, val, val, val);
		return;
	}
	int mid = (l + r) >> 1;
	update_node(id * 2, l, mid, pos, val);
	update_node(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void down(int id, int l, int r)
{
    if (lazy[id] != lim)
    {
        int mid = (l + r) >> 1;
        int x = lazy[id] * (mid - l + 1), y = lazy[id] * (r - mid);
        seg[id * 2] = (x > 0? node(x, x, x, x) : node(lazy[id], x, lazy[id], lazy[id]));
        seg[id * 2 + 1] = (y > 0? node(y, y, y, y) : node(lazy[id], y, lazy[id], lazy[id]));
        lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
        lazy[id] = lim;
    }
}

void update_set(int id, int l, int r, int u, int v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
	    int opt = max(val, val * (r - l + 1));
		seg[id] = node(opt, val * (r - l + 1), opt, opt);
		lazy[id] = val;
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
    if (u > r || v < l) return node(0, 0, inf, inf);
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u])
	if (v != p)
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

	chain[s] = cur_chain;
	pos[s] = ++cur_pos;
	update_node(1, 1, n, cur_pos, a[s]);
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

void Up(int u, int v, int x)
{
    while (chain[u] != chain[v])
    {
        if (chain[u] > chain[v]) swap(u, v);
        update_set(1, 1, n, top[v], pos[v], x);
        v = nex[v];
    }
    if (pos[u] > pos[v]) swap(u, v);
    update_set(1, 1, n, pos[u], pos[v], x);
}
void C(node a)
{
    cout << "(" << a.ans << ' ' << a.sum << ' ' << a.pre << ' ' << a.suf << ") ";
}
void Query(int u, int v)
{
    node t1 = node(0, 0, inf, inf),  t2 = t1;
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
    if (pos[u] < pos[v]) t2 = tmp + t2;
    else t1 = tmp + t1;
    swap(t1.pre, t1.suf);
    cout << max(0ll, (t1 + t2).ans) << '\n';
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt","r", stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	hld(1);

	fill(lazy, lazy + n * 4 + 1, lim);
    while (q--)
    {
        int kind, u, v, x;
        cin >> kind >> u >> v;
        if (kind == 1)
            Query(u, v);
        else
        {
            cin >> x;
            Up(u, v, x);
        }
    }
}
