#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

vector <int> g[100005];
bool vs[100005];

void dfs(int u)
{
    vs[u] = true;
    for (int v : g[u]) if (!vs[v]) dfs(v);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i), cnt ++;
    cout << cnt;
}
