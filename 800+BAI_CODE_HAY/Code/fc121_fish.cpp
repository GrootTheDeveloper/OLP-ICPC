#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
struct node
{
    int sum, MAX, cnt;
    node friend operator+(const node &a, const node &b)
    {
        return {a.sum + b.sum, max(a.MAX, b.MAX), a.cnt + b.cnt};
    }
}seg[N * 4];
int lazy[N * 4];
int nex[N], pos[N], sz[N], top[N], face[N], chain[N];
int cur_pos, cur_chain;
int a[N];
int n, M, q;
vector<int> g[N];

void update_node(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        seg[id] = {val, val, 0};
        if (val == M)
            seg[id].cnt = 1, seg[id].MAX = -1;
        return;
    }
    int mid = (l + r) >> 1;
    update_node(id * 2, l, mid, pos, val);
    update_node(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void down(int id, int l, int r)
{
    if (lazy[id])
    {
        int mid = (l + r) >> 1, tmp = lazy[id];
        if (seg[id * 2].MAX != -1)
        {
            seg[id * 2].sum += tmp * (mid - l + 1 - seg[id * 2].cnt);
            seg[id * 2].MAX += tmp;
            lazy[id * 2] += tmp;
        }
        if (seg[id * 2 + 1]. MAX != -1)
        {
            seg[id * 2 + 1].sum += tmp * (r - mid - seg[id * 2 + 1].cnt);
            seg[id * 2 + 1].MAX += tmp;
            lazy[id * 2 + 1] += tmp;
        }
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        if (seg[id].MAX == -1) return;
        seg[id].sum += (r - l + 1 - seg[id].cnt) * val;
        seg[id].MAX += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id].sum;
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void walk(int id, int l, int r)
{
    if (seg[id].MAX < M) return;
    if (l == r)
    {
        seg[id].sum = M;
        seg[id].cnt = 1;
        seg[id].MAX = -1;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    walk(id * 2, l, mid);
    walk(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
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
        nex[s] = p;
        top[s] = cur_pos + 1;
    }
    pos[s] = ++cur_pos;
    update_node(1, 1, n, cur_pos, a[s]);
    chain[s] = cur_chain;
    top[s] = top[face[cur_chain]];
    nex[s] = nex[face[cur_chain]];
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt] && v != p) nxt = v;
    if(nxt) hld(nxt, s);
    for (int v : g[s])
    if (v != p && v != nxt)
        cur_chain++, hld(v, s);
}

void Up(int u, int v, int x)
{
    while (chain[u] != chain[v])
    {
        if (chain[u] > chain[v]) swap(u, v);
        update(1, 1, n, top[v], pos[v], x);
        walk(1, 1, n);
        v = nex[v];
    }
    if (pos[u] > pos[v]) swap(u, v);
    update(1, 1, n, pos[u], pos[v], x);
    walk(1, 1, n);
}

int query(int u, int v)
{
    int ans = 0;
    while (chain[u] != chain[v])
    {
        if (chain[u] > chain[v]) swap(u, v);
        ans += get(1, 1, n, top[v], pos[v]);
        v = nex[v];
    }
    if (pos[u] > pos[v]) swap(u, v);
    ans += get(1, 1, n, pos[u], pos[v]);
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//  freopen("input.inp","r",stdin);
//  freopen("output.out","w",stdout);

    cin >> n >> M >> q;
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
    while (q--)
    {
        int kind, u, v; cin >> kind >> u >> v;
        if (kind == 0)
        {
            int x; cin >> x;
            Up(u, v, x);
        } else cout << query(u, v) << '\n';
    }

}
