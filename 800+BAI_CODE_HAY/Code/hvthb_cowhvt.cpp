#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[255];
bool vs[255];

void dfs(int u)
{
    if (vs[u]) return;
    vs[u] = true;
    for (int v : g[u])
        dfs(v);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("cow.inp","r",stdin);
    freopen("cow.out","w",stdout);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (!vs[i]) cout << i << '\n', cnt ++;
    if (cnt == 0) cout << 0;
}
