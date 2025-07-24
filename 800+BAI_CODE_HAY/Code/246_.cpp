#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
ii eg[100005];
vector<int> g[100005];
int num[100005], low[100005], numChild[100005];
bool vs[100005], isCut[100005];
int cnt;

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
            numChild[u]++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (num[u] <= low[v]) isCut[u] = true;
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
        eg[i] = make_pair(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    if (!num[i])
    {
        dfs(i);
        if (numChild[i] == 1) isCut[i] = false;
    }
    vector<int> Cut;
    for (int i = 1; i <= n; i++)
        if (isCut[i]) Cut.push_back(i);
    cout << Cut.size() << '\n';
    for (int c : Cut) cout << c << ' ';
}
