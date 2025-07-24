#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> g[100005];
int d[100005], up[100005][18], cnt[100005];
void dfs(int u, int p = 0)
{
    up[u][0] = p;
    cnt[u] = 1;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        dfs(v, u);
        cnt[u] += cnt[v];
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
    if (d[u] > d[v]) swap(u, v);
    v = lift(v, d[v] - d[u]);
    if (u == v) return u;
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
        if (u == v) { cout << n - 1 << '\n'; continue;}
        int x = lca(u, v);
        int w = d[u] + d[v] - 2 * d[x];
        if (w&1) cout << 0;
        else
        {
            int rot;
            if (d[u] - d[x] >= w / 2) rot = lift(u, w / 2);
            else rot = lift(v, w / 2);
            u = lift(u, w / 2 - 1);
            v = lift(v, w / 2 - 1);
            //cout << rot << ' ' << cnt[rot] << ' ' << u << ' ' << v << ' ';
            int ex = 0;
            bool msk = (rot == x);
            if (d[u] > d[rot]) ex += cnt[u];
            if (d[v] > d[rot]) ex += cnt[v];
            if (msk) cout << n - ex;
            else cout << cnt[rot] - ex;

        }
        cout << '\n';

    }
}
