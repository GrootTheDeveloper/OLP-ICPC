/*#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[1005];
int d[1001][1001], n, q;


void inp()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
}
void dijkstra(int s)
{
    d[s][s] = 0;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0,s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[s][u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[s][v] > d[s][u] + w)
            {
                d[s][v] = d[s][u] + w;
                q.push({d[s][v], v});
            }
        }
    }

}
void solve()
{
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = inf;
    for (int i = 1; i <= n; i++) dijkstra(i);
    for (int u,v; q--;)
    {
        cin >> u >> v;
        cout << d[u][v] << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[1005];
int par[1001][15], h[1001], d[1001], n, q;


void dfs(int u, int p = 0)
{
    par[u][0] = p;
    for (int i = 1; i <= 10; i++)
        par[u][i] = par[par[u][i-1]][i-1];
    for (ii x : g[u]) if (x.fi != p)
    {
        int v = x.fi, w = x.se;
        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}
int lift(int u, int k)
{
    for (int i = 10; i >= 0; i--)
        if (k >> i & 1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] > h[v]) swap(u,v);
    v = lift(v, h[v] - h[u]);
    if (u == v) return u;
    for (int i = 10; i >= 0; i--)
        if (par[u][i] != par[v][i])
            {
                u = par[u][i];
                v = par[v][i];
            }
    return par[u][0];
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dfs(1);
    while (q --)
    {
        int u,v; cin >> u >> v;
        int x = lca(u,v);
        cout << d[u] + d[v] - 2 * d[x] << '\n';
    }

}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

}















