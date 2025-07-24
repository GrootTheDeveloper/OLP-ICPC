#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e5 + 5;
int a[N], d[N], up[N][19], seg[N * 4], sz[N];
int cur_chain, cur_pos, chain[N], nex[N], pos[N], pos_lead[N], face[N];
int n, q;
vector <int> g[N];
void dfs(int u, int p = 0)
{
    up[u][0] = p;
    for (int i = 1; i <= 18; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    sz[u] = 1;
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int lift(int k, int v)
{
    for (int i = 18; i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}
int _lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    v = lift(d[v] - d[u], v);
    if (v == u) return u;
    for (int i = 18; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
void update(int id, int l, int r, const int &pos, const int &val)
{
    if (pos > r || pos < l) return;
    if (l == r && l == pos) return seg[id] = val, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
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
    chain[s] = cur_chain;
    nex[s] = nex[face[cur_chain]];
    pos_lead[s] = pos_lead[face[cur_chain]];
    update(1, 1, n, cur_pos, a[s]);
    int nxt = 0;
    for (int v : g[s])
        if (v != p && sz[v] > sz[nxt]) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
    {
        if (v != nxt && v != p)
        {
            cur_chain++;
            hld(v, s);
        }
    }
}

int get(int id, int l, int r, const int &u, const int &v)
{
    if (u > r || v < l) return 1000000000;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int query(int u, int v)
{
    int ans = 1e9;
    while (chain[u] != chain[v])
    {
        if (chain[u] > chain[v]) swap(u, v);
        ans = min(ans, get(1, 1, n, pos_lead[v], pos[v]));
        v = nex[v];
    }
    return min(ans, get(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v])));
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 1e9;
    dfs(1);
    hld(1);
    while (q--)
    {
        int s, t, x; cin >> s >> t >> x;
        int lca = _lca(s, t);
        while (s != lca)
        {
            int l = 0, r = d[s] - d[lca];
            int ans = lca;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                int k = lift(mid, s);
                if (query(s, k) <= x) ans = k, r = mid - 1;
                else l = mid + 1;
            }
            x %= a[ans];
            s = ans;
        }
        x %= a[lca];
        while (s != t)
        {
            int l = 0, r = d[t] - d[s];
            int ans = t;
            while (l <= r)
            {
                int mid =  (l + r) >> 1;
                int k = lift(mid, t);
                if (query(s, k) <= x) ans = k, l = mid + 1;
                else r = mid - 1;
            }
            x %= a[ans];
            s = ans;
        }
        x %= a[t];
        cout << x << '\n';
    }
}













