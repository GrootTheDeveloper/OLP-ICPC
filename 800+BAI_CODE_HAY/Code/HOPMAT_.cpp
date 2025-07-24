#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[101], d[1001];
bool vs[1001];
vector <int> g[1001];

void dfs(int u)
{
    if (vs[u]) return;
    vs[u] = true;
    d[u] ++;
    for (int v : g[u])
        dfs(v);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("hopmat.inp","r",stdin);
    freopen("hopmat.out","w",stdout);
    int k,n,m; cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= k; i++)
    {
        memset(vs, false, sizeof(vs));
        dfs(a[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res += (d[i] == k);
    cout << res;
}
