#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii eg[100004];
vector <int> adj[10004];
int n,m;
int num[10004], low[10004], timer = 0;
bool vs[100004], isCut[10004];
set<ii> br;
void dfs(int u)
{
    low[u] = n + 1;
    num[u] = ++timer;
    for (int id : adj[u]) if (!vs[id])
    {
        vs[id] = true;
        int v = eg[id].fi + eg[id].se - u;
        if (!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) br.insert({min(u,v),max(u,v)});
            if (low[v] >= num[u]) isCut[u] = true;
        } else low[u] = min(low[u], num[v]);
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("worldnet.inp","r",stdin);
    //freopen("worldnet.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        eg[i] = {u,v};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (num[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) if (isCut[i]) cout << i << ' ';
}
