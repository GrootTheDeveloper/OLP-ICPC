#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int par[N], Sz[N], d[N], leader_chain[N], face[N], seg[N * 4];
int Cur_block, Cur_pos, pos[N], a[N], val[N];
vector <int> g[N];
int n, q;
void dfs(int u, int p = 0)
{
    Sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] + 1;
        par[v] = u;
        dfs(v, u);
        Sz[u] += Sz[v];
    }
}

void Hld(int s, int p = 0)
{
    if (face[Cur_block] == 0)
        face[Cur_block] = s;
    a[++Cur_pos] = s;
    pos[s] = Cur_pos;
    leader_chain[s] = Cur_block;
    int vertex = 0;
    for (int v : g[s])
        if (d[v] > d[vertex] && v != p) vertex = v;
    if (vertex) Hld(vertex, s);
    for (int v : g[s])
        if (v != vertex && v != p)
        {
            Cur_block++;
            Hld(v, s);
        }
}

void build(int id, int l, int r)
{
    if (l == r) return seg[id] = val[a[l]], void();
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int value)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
        return seg[id] = value, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, value);
    update(id * 2 + 1, mid + 1, r, pos, value);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}


int query(int u, int v)
{
    int ans = 0;
    while (leader_chain[u] != leader_chain[v])
    {
        if (d[face[leader_chain[u]]] > d[face[leader_chain[v]]]) swap(u, v);
        ans = max(ans, get(1, 1, n, pos[face[leader_chain[v]]], pos[v]));
        v = par[face[leader_chain[v]]];
    }
    if (d[u] > d[v]) swap(u, v);
    ans = max(ans, get(1, 1, n, pos[u], pos[v]));
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    Hld(1);
    build(1, 1, n);
    while (q--)
    {
        int kind, x, y; cin >> kind >> x >> y;
        if (kind == 1)
            update(1, 1, n, pos[x], y);
        else
            cout << query(x, y) << ' ';
    }
}
