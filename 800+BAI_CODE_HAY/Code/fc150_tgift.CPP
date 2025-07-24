#include <bits/stdc++.h>
using namespace std;
#define int long long

set <int> s[200005], LCA[200005];
int up[200005][19], d[200005], a[200005];
vector <int> g[200005];
void dfs(int u, int p = 0)
{
    up[u][0] = p;
    for (int i = 1; i <= 18; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int lift(int k, int v)
{
    for (int i = 18; i>=0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
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
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) cin >> a[i], s[a[i]].insert(i);
    dfs(1);
    for (int i = 1; i < m; i++)
        LCA[lca(a[i], a[i + 1])].insert(i);
    while (q--)
    {
        int kind, x, y, u;
        cin >> kind >> x >> y;
        if (kind == 1)
        {
            s[a[x]].erase(x);
            if (x > 1) LCA[lca(a[x], a[x - 1])].erase(x - 1);
            if (x < m) LCA[lca(a[x], a[x + 1])].erase(x);
            a[x] = y;
            s[a[x]].insert(x);
            if (x > 1) LCA[lca(a[x], a[x - 1])].insert(x - 1);
            if (x < m) LCA[lca(a[x], a[x + 1])].insert(x);
        } else
        {
            cin >> u;
            auto it = s[u].lower_bound(x);
            if (it != s[u].end())
            {
                if (*it <= y)
                {
                    cout << *it << ' ' << *it << '\n';
                    continue;
                }

            }
            auto ac = LCA[u].lower_bound(x);
            if (ac != LCA[u].end())
            {
                if (*ac < y)
                {
                    cout << *ac << ' ' << *ac + 1 << '\n';
                    continue;
                }
            }
            cout << "-1 -1" << '\n';
        }

    }

}
