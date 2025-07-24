#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
const int inf = 1e9, maxn = 1e5 + 5;

struct dta
{
    int node,w;
    dta(int a, int b)
    {
        node = a;
        w = b;
    }
    bool operator< (const dta &other) const
    {
        return node < other.node;
    }
};
vector <dta> g[maxn];
int par[maxn][19], d[maxn], n;
int MAX[maxn][19], MIN[maxn][19];

void dfs(int u, int p = 0, int w = 0)
{
    par[u][0] = p;
    MAX[u][0] = w;
    MIN[u][0] = w;
    for (int i = 1; i <= 18; i++)
    {
        par[u][i] = par[par[u][i-1]][i-1];
        MAX[u][i] = max(MAX[u][i-1], MAX[par[u][i-1]][i - 1]);
        MIN[u][i] = min(MIN[u][i-1], MIN[par[u][i-1]][i - 1]);
    }
    for (dta x : g[u]) if (x.node != p)
    {
        int v = x.node, w = x.w;
        d[v] = d[u] + 1;
        dfs(v,u,w);
    }
}

void lca(int u, int v)
{
    if (d[v] < d[u]) swap(u,v);
    int mi = inf, mx = -inf, k = d[v] - d[u];
    for (int i = 18; i >= 0; i--)
        if (k >> i & 1)
        {
            mi = min(mi, MIN[v][i]);
            mx = max(mx, MAX[v][i]);
            v  = par[v][i];
        }
    if (u == v)
    {
        cout << mi << ' ' << mx << '\n';
        return;
    }
    for (int i = 18; i >= 0; i--)
        if (par[u][i] != par[v][i])
        {
            mi = min({mi, MIN[u][i], MIN[v][i]});
            mx = max({mx, MAX[u][i], MAX[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    mi = min({mi, MIN[u][0], MIN[v][0]});
    mx = max({mx, MAX[u][0], MAX[v][0]});
    cout << mi << ' ' << mx << '\n';
}


void inp()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back(dta(v,w));
        g[v].push_back(dta(u,w));
    }
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
}

void solve()
{
    dfs(1);
    int q; cin >> q;
    while (q--)
    {
        int a,b; cin >> a >> b;
        lca(a,b);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
