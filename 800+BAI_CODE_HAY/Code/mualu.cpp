#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

vector <ii> g[100005];
bool vs[100005];
int n, m, x;
void dfs(int u)
{
    vs[u] = true;
    for (auto e : g[u])
    {
        int v = e.fi, w = e.se;
        if (!vs[v] && w >= x)
            dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) if (!vs[i]) res++, dfs(i);
    cout << res;
}
