#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 2e4 + 5, maxbr = 5e4 + 5;
ii eg[maxbr];
vector <int> g[maxn];
bool isBr[maxbr], vs[maxbr], visited[maxn];
int num[maxn], low[maxn], timer;
int n,m;
void dfs(int u)
{
    num[u] = ++timer;
    low[u] = n + 1;
    for (int id : g[u]) if (!vs[id])
    {
        vs[id] = true;
        int v = eg[id].fi + eg[id].se - u;
        if (!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) isBr[id] = true;
        } else low[u] = min(low[u], num[v]);
    }
}

void bfs(int u)
{
    visited[u] = true;
    for (int id : g[u])
    {
        int v = eg[id].fi + eg[id].se - u;
        if (!visited[v]) bfs(v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        eg[i] = {u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    int scc = -1;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0) dfs(i);
        if (!visited[i]) scc++, bfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int res = 0, cnt = g[i].size();
        for (int id : g[i]) res += isBr[id];
        res += (cnt - res != 0);
        cout << scc + res << '\n';
    }
}
