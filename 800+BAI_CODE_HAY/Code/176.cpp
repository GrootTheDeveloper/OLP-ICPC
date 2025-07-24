#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int inf = 1e15;

vector <ii> g[200005];
int d[7][200005], par[200005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) d[j][i] = inf;
    priority_queue <iii, vector<iii>, greater<iii>> q;
    q.push({0,{0,1}});
    d[0][1] = 0;
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int u = top.se.se, kc = top.fi, num = top.se.fi;
        if (kc > d[num][u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[num][v] > d[num][u] + w)
            {
                d[num][v] = d[num][u] + w;
                q.push({d[num][v],{num,v}});
            }
            if (d[num + 1][v] > d[num][u] && num + 1 <= k)
            {
                d[num + 1][v] = d[num][u];
                q.push({d[num + 1][v], {num + 1, v}});
            }
        }
    }
    int res = inf;
    for (int i = 0; i <= k; i++) res = min(res, d[i][n]);
    if (res == inf) res = -1;
    cout << res;

}
