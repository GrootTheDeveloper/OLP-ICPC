#include <bits/stdc++.h>
using namespace std;

int up[200005][19], d[200005];
vector <int> g[200005];

void dfs(int u, int p = -1)
{
    up[u][0] = p;
    for (int i = 1; i <= 18; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : g[u])
    {
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int lift(int k, int v)
{
    for (int i = 18; i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}

int lca(int u, int v)
{
    if (d[v] < d[u]) swap(u, v);
    v = lift(d[v] - d[u], v);
    if (u == v) return u;
    for (int i = 18; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int ai; cin >> ai;
        g[ai].push_back(i);
    }
    dfs(1);
    //for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    while (q--)
    {
        int u, v; cin >> u >> v;
        if (d[u] < v) cout << -1;
        else cout << lift(v, u);
        cout << '\n';
    }

}
