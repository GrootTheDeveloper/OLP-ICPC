#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e12;
vector <vector<ii>> g,rg;
int n,m,k,s,t;
void enter()
{
    cin >> n >> m >> k >> s >> t;
    g.assign(n + 2, vector<ii>());
    rg.assign(n + 2, vector<ii>());
    for (int i = 1; i <= m; i++)
    {
        int x, y, w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        rg[y].emplace_back(x,w);
    }
}

void dijkstra(int s, vector <vector<ii>> &g, vector <int> &d)
{
    d[s] = 0;
    priority_queue <ii, vector <ii>, greater<ii>> q;
    q.push({0,s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u]) continue;
        for (ii x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
}
void solve()
{
    enter();
    vector <int> d1(n + 2, inf), d2(n + 2, inf);
    dijkstra(s, g, d1);
    dijkstra(t, rg, d2);
    int res = d1[t];
    while (k--)
    {
        int x, y, w; cin >> x >> y >> w;
        res = min({res, d1[x] + d2[y] + w, d1[y] + d2[x] + w});
    }
    if (res >= inf) res = -1;
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}

