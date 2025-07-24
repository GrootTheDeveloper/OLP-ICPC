#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 100;
int pos_lead[N], pos[N], nex[N], sz[N], d[N];
int face[N], cur_chain, cur_pos, tout[N], chain[N];
int n, q;
vector <int> g[N];
long long seg[N * 4], lazy[N * 4];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v != p)
        {
            d[v] = d[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void hld(int s, int p = 0)
{
    if (!face[cur_chain])
        face[cur_chain] = s;
    pos[s] = ++cur_pos;
    chain[s] = cur_chain;
    pos_lead[s] = pos_lead[face[chain[s]]];
    nex[s] = nex[face[chain[s]]];
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt] && v != p) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != nxt && v != p)
        {
            cur_chain++;
            pos_lead[v] = cur_pos+1;
            nex[v] = s;
            hld(v, s);
        }
    tout[s] = cur_pos;
}
void down(int id, int l, int r)
{
    if (lazy[id])
    {
        int mid = (l + r) >> 1;
        long long tmp = lazy[id];
        seg[id << 1] += (mid - l + 1) * tmp;
        seg[id << 1 | 1] += (r - mid) * tmp;
        lazy[id << 1] += tmp;
        lazy[id << 1 | 1] += tmp;
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, const int &u, const int &v, const int &val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] += val * (ll)(r - l + 1);
        lazy[id] += val;
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
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
        int kind, u, v, x;
        cin >> kind;
        if (kind == 1)
        {
            cin >> u;
            cout << get(1, 1, n, pos[u], tout[u]) << '\n';
        }
        if (kind == 2)
        {
            cin >> u;
            cout << get(1, 1, n, pos[u], pos[u]) << '\n';
        }
        if (kind == 3)
        {
            cin >> u >> v >> x;
            while (chain[u] != chain[v])
            {
                if (chain[u] > chain[v]) swap(u, v);
                update(1, 1, n, pos_lead[v], pos[v], x);
                v = nex[v];
            }
            update(1, 1, n, min(pos[u], pos[v]), max(pos[u], pos[v]), x);
        }
    }
}
