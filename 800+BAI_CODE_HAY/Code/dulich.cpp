#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,pair<int,pair<int,int>>>
#define fi first
#define se second
const int inf = 1e15;


struct dta
{
    int cost,u,num;
    bool iuu;
    dta(int _cost, int _u, int _num, bool _iuu)
    {
        cost = _cost;
        u    = _u;
        num  = _num;
        iuu  = _iuu;
    }
    bool operator< (const dta &other) const {
        return cost > other.cost;
    }
};
vector<ii> g[1003];
int pw[1001][1001];
int d[1005][505][2];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    ///////input
    for (int i = 1; i <= m; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        pw[x][y] = w >> 1;
    }
    /////// Dijkstra
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) d[i][j][0] = d[i][j][1] = inf;
    d[1][0][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> q;
    q.push({0,{1,{0,0}}});
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int u = top.se.fi, cost = top.fi, num = top.se.se.fi;
        bool type = top.se.se.se;
        if (cost > d[u][num][type]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v][num][0] > d[u][num][type] + w)
            {
                d[v][num][0] = d[u][num][type] + w;
                q.push({d[v][num][0],{v, {num, 0}}});
            }
            if (!type)
            {
                if (d[v][num + 1][1] > (d[u][num][0] + pw[u][v]) && num < k)
                {
                    d[v][num + 1][1] = d[u][num][0] + pw[u][v];
                    q.push({d[v][num + 1][1],{v,{num + 1, 1}}});
                }
            }
        }
    }
    int res = inf;
    for (int i = 0; i <= k; i++)
        res = min({res, d[n][i][1], d[n][i][0]});
    if (res == inf) res = -1;
    cout << res;
}
