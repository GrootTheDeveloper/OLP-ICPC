#include <bits/stdc++.h>
using namespace std;
#define int long long

int d[100005], par[100005];
vector <int> g[100004];
void dfs(int u, int p = -1)
{
    for (auto v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
}
int ans[100005], x, y, val;



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    d[0] = -1;
    par[1] = 0;
    while (q--)
    {
        int u,v,x; cin >> u >> v >> x;
        vector <int> node;
        while (d[v] >= d[u])
        {
            if (ans[v] == 0)  ans[v] = x;
            node.push_back(v);
            v = par[v];
        }
        for (int e : node) par[e] = v;

    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

}
