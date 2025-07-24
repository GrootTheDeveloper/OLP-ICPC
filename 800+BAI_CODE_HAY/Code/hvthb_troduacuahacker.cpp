#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5;

ii eg[maxn];
vector <int> g[maxn];
int n, m, num[maxn], low[maxn], timer;
bool vs[maxn], isBr[maxn];

void dfs(int u)
{
    num[u] = ++timer;
    low[u] = n + 1;
    for (auto id : g[u]) if (!vs[id])
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

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("hacker.inp","r",stdin);
    freopen("hacker.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        eg[i] = {u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (num[i] == 0) dfs(i);
    int q; cin >> q;
    while (q--)
    {
        int x; cin >> x;
        cout << ((isBr[x])? "Unhappy" : "Happy") << '\n';
    }
}
