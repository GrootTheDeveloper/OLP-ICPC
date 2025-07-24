#include <bits/stdc++.h>
using namespace std;
//#define int long long
int tin[100005], a[200005], d[100005];
int ti;
int log2(int n) {return 31 - (int)__builtin_clz(n);}
int up[100005][18];
vector <int> g[100005];
void dfs(int u, int p = 0)
{
    tin[u] = ++ti;
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != p)
            d[v] = d[u] + 1, dfs(v, u);
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    int k = d[v] - d[u];
    for (int i = log2(d[v]); i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    if (v == u) return u;
    for (int i = log2(d[v]); i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
bool cmp(int a, int b)
{
    return tin[a] < tin[b];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
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
        int x; cin >> x;
        for (int i = 1; i <= x; i++) cin >> a[i];
        sort(a + 1, a + x + 1, cmp);
        int temp = a[1], res = a[1];
        for (int i = 2; i <= x; i++)
        {
            int m = lca(a[1], a[i]);
            if (d[m] <= d[temp]) temp = m, res = a[i];
        }
        cout << a[1] << ' ' << res << '\n';
    }
}
