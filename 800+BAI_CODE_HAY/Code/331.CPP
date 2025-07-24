#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int face[N], chain[N], pos[N], par[N], tout[N], sz[N], d[N];
int cur_pos, cur_block;
vector <int> g[N];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p) continue;
        par[v] = u;
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }

}

void hld(int s, int p = 0)
{
    if(face[cur_block] == 0)
        face[cur_block] = s;

    pos[s] = ++cur_pos;
    chain[s] = cur_block;
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt] && v != p) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != p && v != nxt)
        {
            cur_block++;
            hld(v, s);
        }
    tout[s] = cur_pos;
}
struct Segmentree
{
    vector <int> seg, lazy;
    int n;
    Segmentree (int _n)
    {
        n = _n;
        seg.assign(n * 4 + 5, 0);
        lazy.assign(n * 4 + 5, 0);
    }
    void down(int id, int l, int r)
    {
        int mid = (l + r) >> 1;
        if (lazy[id])
        {
            seg[id * 2 ] += lazy[id] * (mid - l + 1);
            seg[id * 2 + 1] += lazy[id] * (r - mid);
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (u > r || v < l) return;
        if (u <= l && r <= v)
        {
            seg[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
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
    void update(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }
    int get(int pos)
    {
        return get(1, 1, n, pos, pos);
    }
};
signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    hld(1);
    Segmentree st(n);
    while (q--)
    {
        int kind, u, v;
        cin >> kind;
        if (kind == 1)
        {
            cin >> u >> v;
            st.update(pos[u], tout[u], v);
        } else
        {
            cin >> u;
            cout << st.get(pos[u]) << '\n';
        }
    }



}