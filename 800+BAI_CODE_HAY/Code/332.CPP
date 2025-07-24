#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, seg[N * 4], pos[N], par[N], face[N], chain[N], sz[N];
int cur_pos, cur_chain;
vector <int> g[N];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p) continue;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void hld(int s, int p = 0)
{
    if (!face[cur_chain])
         face[cur_chain] = s;
    pos[s] = ++cur_pos;
    chain[s] = cur_chain;
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
void update(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l) return seg[id] = 1, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos);
    update(id * 2 + 1, mid + 1, r, pos);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void Up(int pos)
{
    update(1, 1, n, pos);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
int Get(int l, int r)
{
    return get(1, 1, n, l, r);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    hld(1);
    for (int i = 1; i <= n; i++)
    {
        int u; cin >> u;
        int x = u;
        int ans = 0;
        while (chain[u] != chain[1])
        {
            ans += Get(pos[face[chain[u]]], pos[u]);
            u = par[face[chain[u]]];
        }
        ans += Get(pos[1], pos[u]);
        cout << ans << '\n';
        Up(pos[x]);
    }
}