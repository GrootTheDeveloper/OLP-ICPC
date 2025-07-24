#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second


struct DSU
{
    vector <int> par, sz;
    DSU (int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += b;
    }
    bool check(int a, int b)
    {
        a = find(a); b = find(b);
        return a == b;
    }
};
int up[100005][18], flow[100005][18], d[100005], cnt[100005];
iii eg[100005];
int n,q;
vector <int> g[100005];
void dfs_pre(int u, int p = 0, int w = 1e9)
{
    up[u][0] = p;
    flow[u][0] = w;
    for (int i = 1; i <= 17; i++)
    {
        flow[u][i] = min(flow[u][i - 1], flow[up[u][i-1]][i - 1]);
        up[u][i] = up[up[u][i-1]][i - 1];
    }
    for (int id : g[u])
    {
        int v = eg[id].fi.fi + eg[id].fi.se - u, w = eg[id].se;
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs_pre(v,u,w);
    }
}
int min_cost(int u, int v)
{
    if (u == v) return 0;
    if (d[u] > d[v]) swap(u,v);
    int dic = d[v] - d[u];
    int res = 1e9;
    for (int i = 17; i >= 0; i--)
        if (dic >> i & 1)
        {
            res = min(res, flow[v][i]);
            v = up[v][i];
        }
    if (u == v) return res;
    for (int i = 17; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            res = min({res,flow[u][i],flow[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    res = min({res, flow[u][0],flow[v][0]});
    return res;
}
int type[100005], opx[100005], opy[100005], ans[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        eg[i] = {{x,y},w};
        g[x].push_back(i);
        g[y].push_back(i);
    }
    dfs_pre(1);
   // cout << min_cost(1,3) << ' ' << min_cost(1,5);
    for (int i = 1; i <= q; i++)
    {
        cin >> type[i];
        if (type[i] == 1) cin >> opx[i] >> opy[i];
        else
        {
            cin >> opx[i];
            for (int id : g[opx[i]])
                cnt[id]++;
        }
    }
    DSU dsu(n);
    for (int i = 1; i < n; i ++)
        if (!cnt[i]) dsu.Union(eg[i].fi.fi, eg[i].fi.se);
    for (int i = q; i >= 1; i--)
    {
        if (type[i] == 1)
        {
            if (dsu.check(opx[i], opy[i])) ans[i] = min_cost(opx[i],opy[i]);
            else ans[i] = -1;
        }else
        {
            for (int id : g[opx[i]])
            {
                cnt[id]--;
                if (cnt[id] == 0) dsu.Union(eg[id].fi.fi, eg[id].fi.se);
            }
        }
    }
    for (int i = 1; i <= q; i++) if (type[i] == 1) cout << ans[i] << '\n';
}
