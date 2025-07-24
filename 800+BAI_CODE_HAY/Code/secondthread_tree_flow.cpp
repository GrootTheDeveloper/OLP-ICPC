#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 3e5 + 5;
vector <ii> g[300005];
int par[maxn][20], MIN[maxn][20];
int n, d[maxn], m;
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
}
void dfs(int u, int p = 0, int w = 0)
{
    par[u][0] = p;
    MIN[u][0] = w;
    for (int i = 1; i <= 19; i++)
    {
        MIN[u][i] = min(MIN[u][i-1],MIN[par[u][i-1]][i-1]);
        par[u][i] = par[par[u][i-1]][i-1];

    }
    for (ii x : g[u]) if (x.fi != p)
    {
        int v = x.fi, w = x.se;
        d[v] = d[u] + 1;
        dfs(v,u,w);
    }
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u,v);
    int res = INT_MAX;
    for (int i = 19; i >= 0; i--)
        if (d[v] - d[u] >> i & 1)
        {
            res = min(res, MIN[v][i]);
            v = par[v][i];

        }
    if (u == v) return res;
    for (int i = 19; i >= 0; i--)
         if (par[u][i] != par[v][i])
        {

            res = min({res, MIN[u][i], MIN[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    return min({res,MIN[u][0],MIN[v][0]});
}
void solve()
{
    dfs(1);
    int q; cin >> q;
    while (q--)
    {
        int a,b; cin >> a >> b;
        cout << lca(a,b) << '\n';
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();

}
