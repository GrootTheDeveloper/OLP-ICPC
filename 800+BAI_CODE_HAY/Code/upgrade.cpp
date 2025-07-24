#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e12;
vector <ii> g[100005];
vector <int> NewG[100005];
int d[100005], n, m;
bool mark[100005];
int tin[100005], low[100005], timer, res;


void BuilGr(int u, int p = 0)
{
    if (u == 1 || mark[u]) return;
    mark[u] = true;
    for (auto x : g[u])
    {
        int v = x.fi, w = x.se;
        if (v == p) continue;
        if (d[v] + w == d[u])
        {
            NewG[u].push_back(v);
            NewG[v].push_back(u);
            BuilGr(v, u);
        }
    }
}

void dfs(int u, int p = 0)
{
    tin[u] = low[u] = ++timer;
    for (int v : NewG[u])
    {
        if (v == p) continue;
        if (tin[v]) low[u] = min(low[u], tin[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) res++;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    fill(d, d + n + 1, inf);
    queue <ii> q;
    q.push({1, 0});
    d[1] = 0;
    mark[1] = true;
    while (q.size())
    {
        ii top = q.front(); q.pop();
        int u = top.fi, p = top.se;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (v == p) continue;
            if (!mark[v])
            {
                mark[v] = true;
                d[v] = d[u] + w;
                q.push({v, u});
            } else
            {
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    q.push({v, u});
                }
            }
        }
    }
    memset(mark, false, sizeof(mark));
    BuilGr(n);
    dfs(1);
    cout << res;
}