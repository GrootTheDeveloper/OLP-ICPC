#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define fi first
#define se second

vector <ii> g[100005];
int up[100005][18], d[100005], dic[100005];

void dfs(int u, int p = 0, int w = 0)
{
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto x : g[u]) if (x.fi != p)
    {
        int v = x.fi, w = x.se;
        d[v] = d[u] + 1;
        dic[v] = dic[u] + w;
        dfs(v, u);
    }
}
int lift(int v, int k)
{
    for (int i = 17; i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int u, int v)
{
    if (d[v] < d[u]) swap(u, v);
    v = lift(v, d[v] - d[u]);
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    return up[u][0];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dfs(1);
    while (q--)
    {
        int kind, u, v, k;
        cin >> kind >> u >> v;
        if (kind == 1)
        {
            int x = lca(u, v);
            cout << dic[u] + dic[v] - 2 * dic[x] << '\n';
        }
        if (kind == 2)
        {
            cin >> k;
            int x = lca(u, v);
            int costU = d[u] - d[x] + 1, cost = d[u] + d[v] + 1 - 2 * d[x];
            if (costU >= k) cout << lift(u, k - 1) << '\n';
            else cout << lift(v, cost - k) << '\n';
        }
    }
}
