#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5 + 5;
struct node
{
    int l = 0, r = 0, gcd = 0, in = 0;
}seg[N * 4];
node oo;
int lazy[N * 4];
int a[N];
int gcd(node &a, node &b)
{
    return __gcd(__gcd(a.l, b.r), __gcd(a.in, __gcd(b.in, abs(a.r - b.l))));
}
node com(node a, node b)
{
    node ans;
    ans.gcd = gcd(a, b);
    ans.in = __gcd(a.in, __gcd(b.in, abs(a.r - b.l)));
    ans.l = a.l, ans.r = b.r;
    return ans;
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id].l = seg[id].r = seg[id].gcd = a[l];
        seg[id].in = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = com(seg[id * 2], seg[id * 2 + 1]);
}
void down(int id)
{
    if (lazy[id])
    {
        int tmp = lazy[id];
        seg[id << 1].l += tmp, seg[id << 1].r += tmp;
        seg[id << 1].gcd = __gcd(__gcd(seg[id << 1].l, seg[id << 1].r), seg[id << 1].in);

        seg[id << 1 | 1].l += tmp, seg[id << 1 | 1].r += tmp;
        seg[id << 1 | 1].gcd = __gcd(__gcd(seg[id << 1 | 1].l, seg[id << 1 |1].r), seg[id << 1 | 1].in);

        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id].l += val;
        seg[id].r += val;
        seg[id].gcd = __gcd(seg[id].l, seg[id].in);
        lazy[id] += val;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = com(seg[id * 2], seg[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return oo;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return com(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}
int sz[N], chain[N], pos_lead[N], face[N], nex[N], pos[N];
int cur_chain, cur_pos;
vector <int> g[N];
int n, q;
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
        pos_lead[s] = cur_pos + 1;
        nex[s] = p;
    }
    pos[s] = ++cur_pos;
    update(1, 1, n, cur_pos, cur_pos, a[s]);
    chain[s] = cur_chain;
    nex[s] = nex[face[cur_chain]];
    pos_lead[s] = pos_lead[face[cur_chain]];
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt] && v != p) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != nxt && v != p)
        {
            cur_chain++;
            hld(v, s);
        }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    oo.gcd = oo.l = oo.r = 0;
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
        int kind, u, v, x; cin >> kind >> u >> v;
        if (kind == 1)
        {
            cin >> x;
            while (chain[u] != chain[v])
            {
                if (chain[u] > chain[v]) swap(u, v);
                update(1, 1, n, pos_lead[v], pos[v], x);
                v = nex[v];
            }
            update(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v]), x);
        }
        else
        {
            node ans = oo;
            while (chain[u] != chain[v])
            {
                if (chain[u] > chain[v]) swap(u, v);
                ans = com(ans, get(1, 1, n, pos_lead[v], pos[v]));
                v = nex[v];
            }
            ans = com(ans, get(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v])));
            cout << ans.gcd << '\n';
        }
    }

}
