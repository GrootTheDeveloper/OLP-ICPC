#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

vector <ii> g[100005];
int up[100005][18], f[100005][18], d[100005];

void dfs(int u, int p = 0, int w = 0)
{
    up[u][0] = p;
    f[u][0]  = w;
    for (int i = 1; i <= 17; i++)
    {
        f[u][i] = max(f[u][i - 1], f[up[u][i - 1]][i - 1]);
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto x : g[u])
    {
        int v = x.fi, w = x.se;
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, w);
    }
}

int query(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    int res = 0;
    for (int i = 17; i >= 0; i--)
        if (d[v] - d[u] >> i & 1)
        {
            res = max(res, f[v][i]);
            v = up[v][i];
        }
    if (u == v) return res;
    for (int i = 17; i >= 0; i--)
        if (up[u][i] != up[v][i])
        {
            res = max({res, f[u][i], f[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    return max({res, f[u][0], f[v][0]});
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(1);
    while (q--)
    {
        int u, v; cin >> u >> v;
        cout << query(u, v) << '\n';
    }
}
