#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int pos[N], pos_lead[N], sz[N], tout[N], face[N], nex[N];
int seg[N * 4], lazy[N * 4];
int ver[N];
char kind[N];
int cur_pos, cur_chain;
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
void hld(int s, int p = -1)
{
    if (!face[cur_chain])
    {
        face[cur_chain] = s;
        pos_lead[s] = cur_pos + 1;
        nex[s] = p;
    }
    pos[s] = ++cur_pos;
    pos_lead[s] = pos_lead[face[cur_chain]];
    nex[s] = nex[face[cur_chain]];
    int nxt = 0;
    for (int v : g[s])
        if (sz[v] > sz[nxt]) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != nxt){
            cur_chain++;
            hld(v, s);
        }
    tout[s] = cur_pos;
}
void down(int id, int l, int r)
{
    if (lazy[id])
    {
        int tmp = lazy[id], mid = (l + r) >> 1;
        seg[id * 2] += (mid - l + 1) * tmp;
        seg[id * 2 + 1] += (r - mid) * tmp;
        lazy[id * 2] += tmp;
        lazy[id * 2 + 1] += tmp;
        lazy[id] = 0;
    }
}
void updateset(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] = 0;
        lazy[id] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    updateset(id * 2, l, mid, u, v);
    updateset(id * 2 + 1, mid + 1, r, u, v);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
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
    int mid = (l + r) >> 1;
    down(id, l, r);
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
void solve()
{
    update(1, 1, n, pos[1], pos[1], 1);
    int x = 1;
    for (int i = 1; i <= q; i++)
    {
        if (kind[i] == '+')
        {
            x++;
            update(1, 1, n, pos[x], pos[x], 1);
            //cout << seg[1] << '\n';
        }
        if (kind[i] == '-')
        {
            int u = ver[i];
            updateset(1, 1, n, pos[u], tout[u]);
        }
        if (kind[i] == '?')
        {
            int u = ver[i];
            //cout << u << ' ';
            cout << get(1, 1, n, pos[u], tout[u]) << '\n';
        }
    }

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> q;
    n = 1;
    for (int i = 1; i <= q; i++)
    {
        cin >> kind[i] >> ver[i];
        ver[i]++;
        if (kind[i] == '+')
        {
            g[ver[i]].push_back(++n);
            ver[i] = n;
        }
    }
    dfs(1);
    hld(1);
    solve();
}
