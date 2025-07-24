#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int seg[N * 4], lazy[N * 4], nex[N], pos[N], pos_lead[N], chain[N], tout[N], sz[N], d[N];
int up[N][18], face[N];
int cur_chain, cur_pos;
vector <int> g[N];
int n, q;
int a[N];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int lift(int k, int v)
{
    for (int i = 17; i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    v = lift(d[v] - d[u], v);
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
void down(int id, int l, int r)
{
    if (lazy[id])
    {
        int mid = (l + r) >> 1, temp = lazy[id];
        seg[id * 2] += (mid - l + 1) * temp;
        seg[id * 2 + 1] += (r - mid) * temp;
        lazy[id * 2] += temp;
        lazy[id * 2 + 1] += temp;
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val)
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
    update(id * 2 + 1, mid +1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void hld(int s, int p = 0)
{
    if (!face[cur_chain])
    {
        face[cur_chain] = s;
        nex[s] = p;
        pos_lead[s] = cur_pos + 1;
    }
    pos[s] = ++cur_pos;
    update(1, 1, n, cur_pos, cur_pos, a[s]);
    chain[s] = cur_chain;
    pos_lead[s] = pos_lead[face[cur_chain]];
    nex[s] = nex[face[cur_chain]];
    int nxt = 0;
    for (int v : g[s])
        if (v != p && sz[v] > sz[nxt]) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
    {
        if (v != p && v != nxt)
        {
            cur_chain++;
            hld(v, s);
        }
    }
    tout[s] = cur_pos;
}
int siu(int u, int v)
{
    int k = d[v] - d[u];
    if (k <= 1) return v;
    return lift(k - 1, v);
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    hld(1);
    int root = 1;
    while (q--)
    {
        int kind, u, v, val;
        cin >> kind;
        if (kind == 1)
        {
            cin >> u;
            root = u;
        }
        if (kind == 2)
        {
            cin >> u >> v >> val;
            int x = lca(root, u), y = lca(root, v), z = lca(u, v);
            if (pos[root] < pos[z] || pos[root] > tout[z])
                update(1, 1, n, pos[z], tout[z], val);
            else if (root == z) update(1, 1, n, 1, n, val);
            else if (pos[root] >= pos[z] && pos[root] <= tout[z])
            {
                if (d[x] < d[y]) swap(x, y);
                update(1, 1, n, 1, n, val);
                if (x != root)
                {
                    x = siu(x, root);
                    update(1, 1, n, pos[x], tout[x], -val);
                }
            }
        }
        if (kind == 3)
        {
            cin >> u;
            if (pos[root] < pos[u] || pos[root] > tout[u])
                cout << get(1, 1, n, pos[u], tout[u]);
            else
            {
                int ans = seg[1];
                if (u != root)
                {
                    int cl = siu(u, root);
                    ans -= get(1, 1, n, pos[cl], tout[cl]);
                }
                cout << ans;
            }
            cout << '\n';
        }
    }
}
