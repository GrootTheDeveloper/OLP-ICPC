#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[200005];
int d[3][200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++) d[1][i] = d[2][i] = inf;
    d[1][1] = 0;
    priority_queue <iii, vector<iii>, greater<iii>> q;
    q.push({0,{1,1}});
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int u = top.se.se, kc = top.fi, num = top.se.fi;
        if (kc > d[num][u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (num == 1)
            {
                if (d[1][v] > d[1][u] + w)
                {
                    d[1][v] = d[1][u] + w;
                    q.push({d[1][v],{1,v}});
                } else if (d[2][v] > d[1][u] + w && d[1][v] != d[1][u] + w)
                {
                    d[2][v] = d[1][u] + w;
                    q.push({d[2][v],{2,v}});
                }
            }
            if (num == 2)
            {
                if (d[2][v] > d[2][u] + w)
                {
                    d[2][v] = d[2][u] + w;
                    q.push({d[2][v], {2,v}});
                }
            }
        }
    }
    if (d[2][n] == inf) d[2][n] = -1;
    cout << d[2][n];

}
