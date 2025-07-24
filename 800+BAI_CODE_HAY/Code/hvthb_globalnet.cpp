#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
const int maxnode = 1e5 + 5, maxBr = 1e6 + 5;
ii eg[maxBr];
bool vs[maxBr], visited[maxnode], isBr[maxBr], isCut[maxnode];
vector <int> g[maxnode];
int n,m, timer;
int low[maxnode], num[maxnode], numChild[maxnode];
void dfs(int u)
{
    low[u] = n + 1;
    num[u] = ++timer;
    for (int id : g[u]) if (vs[id] == false)
    {
        vs[id] = true;
        int v = eg[id].fi + eg[id].se - u;
        if (num[v] == 0)
        {
            numChild[u]++;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if (low[v] > num[u])  isBr[id] = true;
            if (low[v] >= num[u]) isCut[u] = true;
        } else low[u] = min(low[u], num[v]);
    }
}
int res, cnt;
void dfs_scc(int u)
{
    cnt++;
    visited[u] = true;
    for (int id : g[u]) if (!isBr[id])
    {
        int v = eg[id].fi + eg[id].se - u;
        if (!visited[v]) dfs_scc(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("globalnet.inp","r",stdin);
    freopen("globalnet.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        eg[i] = {u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (num[i] == 0)
    {
        dfs(i);
        if (numChild[i] == 1) isCut[i] = false;
    }
    //for (int i = 1; i <= n; i++) cout << isCut[i];

    for (int i = 1; i <= n; i++)
        if (!visited[i]) cnt = 0, dfs_scc(i), res = max(res,cnt);

    vector <int> vec;
    for (int i = 1; i <= n; i++) if (isCut[i]) vec.push_back(i);
    cout << vec.size() << ' ' << res << '\n';
    for (int x : vec) cout << x << '\n';


}
