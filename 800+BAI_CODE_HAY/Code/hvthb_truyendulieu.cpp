#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

vector <int> g[10005];
int num[10005], low[10005], timer;
set <pair<int,int>> br;
void dfs(int u, int par = -1)
{
    num[u] = low[u] = ++timer;
    for (int v : g[u]) if (v != par)
    {
        if (num[v]) low[u] = min(low[u],num[v]);
        else
        {
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) br.insert({min(u,v), max(u,v)});
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("worldnet.inp","r",stdin);
    freopen("worldnet.out","w",stdout);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        if (num[i] == 0) dfs(i);
    cout << br.size() << '\n';
    for (auto x : br) cout << x.fi << ' ' << x.se << '\n';
}
