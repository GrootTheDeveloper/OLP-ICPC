#include <bits/stdc++.h>
using namespace std;
#define int long long
#define iii pair<int,pair<int,int>>
#define fi first
#define se second
const int inf = 1e9;

struct dta
{
    int node,w,cost;
    dta(int _node, int _w, int _cost)
    {
        node = _node;
        w    = _w;
        cost = _cost;
    }
};

int n, k, r;
int d[105][10005];
vector <dta> g[101];

void dijkstra(int s)
{
    d[s][0] = 0;
    priority_queue <iii, vector<iii>, greater<iii>> q;
    q.push({0,{s,0}});
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int u = top.se.fi, kc = top.fi, t = top.se.se;
        if (kc > d[u][t]) continue;
        for (dta x : g[u])
        {
            int v = x.node, w = x.w, cost = x.cost;
            //if (t + cost > k) continue;
            if (d[v][t + cost] > d[u][t] + w)
            {
                d[v][t + cost] = d[u][t] + w;
                q.push({d[v][t + cost],{v, t + cost}});
            }
        }
    }

}

void solve()
{
    cin >> k >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        g[i].erase(begin(g[i]), end(g[i]));
        for (int j = 1; j <= k; j++) d[i][j] = inf;
    }
    for (int i = 1; i <= r; i++)
    {
        int x,y,l,t; cin >> x >> y >> l >> t;
        g[x].push_back(dta(y,l,t));
       // g[y].push_back(dta(x,l,t));
    }
    dijkstra(1);
    int res = inf;
    for (int i = 1; i <= k; i++) res = min(res, d[n][i]);
    if (res >= inf) cout << -1;
    else cout << res;
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    for (;t--;) solve();

}
