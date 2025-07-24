#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int up[N][18], d[N];
vector <int> g[N];
void dfs(int u, int p = 0)
{
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        dfs(v, u);
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
    if (v == u) return u;
    for (int i = 17; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
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
    while (q--)
    {
        int u, v; cin >> u >> v;
        int x = lca(u, v);
        if (x == u) cout << "MA";
        else if (x == v) cout << "RI";
        else cout << "SA";
        cout << '\n';
    }
}