#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

int up[maxn][20], d[maxn];
vector <int> g[maxn];

void dfs(int u, int p = -1)
{
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
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
    if (d[u] > d[v]) swap(u,v);
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
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int res = 0;
    for (int i = 2; i <= n; i++) res += d[i];
    for (int i = 2; i <= n; i++) for (int j = i; j <= n; j+=i)
    {
        int x = lca(i,j);
        int ans = d[i] + d[j] - 2 * d[x] + 1;
        res += ans;
    }
    cout << res;
}
