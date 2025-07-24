#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second

ii eg[100005];
vector<int> g[100005];
int num[100005], low[100005];
bool isBr[100005], vs[100005];
int cnt = 0;

void dfs(int u)
{
    num[u] = ++cnt;
    low[u] = 1e5 + 5;
    for (int id : g[u]) if (!vs[id])
    {
        vs[id] = true;
        int v = eg[id].fi + eg[id].se - u;
        if (num[v] == 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) isBr[id] = true;
        } else low[u] = min(low[u], num[v]);
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        eg[i] = {u, v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    if (!num[i]) dfs(i);
    vector<int> br;
    for (int i = 1; i <= m; i++)
    if (isBr[i]) br.push_back(i);
    cout << br.size() << '\n';
    for (int c : br) cout << c << ' ';
}
