#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
const int inf = 1e15;
map <ii, bool> f;
vector <ii> g[100005];
int par[100005], d[100005], n, m;
void dijkstra1(int s, int t)
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0,s});
    d[s] = 0;
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                par[v] = u;
                q.push({d[v],v});
            }
        }

    }
    for (int u = t; u != 0; u = par[u])
        f.insert({{min(u,par[u]),max(u,par[u])}, true});
   // cout << d[t] << ' ';
}
void dijkstra2(int s, int t)
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    priority_queue <ii, vector<ii>, greater<ii>>  q;
    q.push({0,s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (d[u] < kc) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (f.find({min(u,v), max(u,v)}) != f.end()) w = 0;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
    cout << d[t] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int s,t,u,v; cin >> s >> t >> u >> v;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    dijkstra1(s,t);
    dijkstra2(u,v);

}
