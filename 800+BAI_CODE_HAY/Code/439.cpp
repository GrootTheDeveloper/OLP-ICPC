#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii eg[3003];
vector <int> g[1001];
int d[1001][1001];
int a[1001];
void bfs(int s)
{
    queue <int> q;
    q.push(s);
    while (q.size()) 
    {
        int u = q.front(); q.pop();
        for (auto id : g[u])
        {
            int v = eg[id].fi + eg[id].se - u;
            if (d[s][v] == 0 && v != s)
            {
                d[s][v] = d[s][u] + 1;
                q.push(v);
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        eg[i]   = {u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 1; i <= k; i++)
        bfs(a[i]);
    int res = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int u = eg[i].fi, v = eg[i].se;
        int ans = 0;
        for (int j = 1; j <= k; j++)
            ans += min(d[a[j]][u], d[a[j]][v]);
        res = min(res, ans);
    }   
    cout << res;
}