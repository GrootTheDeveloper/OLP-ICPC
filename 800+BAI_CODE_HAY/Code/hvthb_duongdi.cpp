#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5;
ii eg[maxn];
vector <int> g[maxn], adj[maxn];
int num[maxn], low[maxn], timer, n, m, numChild[maxn], par[maxn];
bool visited[maxn], vs[maxn], isCut[maxn];
int a,b;
map <ii,bool> f;
void dfs(int u)
{
    num[u] = ++timer;
    low[u] = n  + 1;
    for (int id : adj[u]) if (!vs[id])
    {
        vs[id] = true;
        int v = eg[id].fi + eg[id].se - u;
        if (!num[v])
        {
            numChild[u]++;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if (low[v] > num[u]) f[{min(u,v),max(u,v)}] = true;
        } else low[u] = min(low[u], num[v]);
    }
}
void bfs(int s)
{
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
            if (!visited[v])
            {
                par[v] = u;
                visited[v] = true;
                q.push(v);
            }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("EdgeOnPaths.inp","r",stdin);
    freopen("EdgeOnPaths.out","w",stdout);
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        eg[i] = {u,v};
        adj[u].push_back(i);
        adj[v].push_back(i);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if (num[i] == 0) dfs(i);
    bfs(a);
    int res = 0;
    for (int u = b; u != 0; u = par[u]) res += (f.find({min(u,par[u]),max(u,par[u])}) != f.end());
    cout << res;

}
