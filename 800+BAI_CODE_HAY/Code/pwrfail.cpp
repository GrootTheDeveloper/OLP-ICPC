#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <long,long>
#define iii pair <int,double>
#define rii pair <double,int>
#define fi first
#define se second

bool f[1001][1001];
pair <int,int> idx[1001];
vector <iii> g[1001];
int n, w;
double m, d[1005];
const double inf = 1e15;
double calc(ii a, ii b)
{
    return sqrt((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se-b.se));
}
void inp()
{
    cin >> n >> w;
    cin >> m;
    for (int i = 1; i <= n; i++)
        cin >> idx[i].fi >> idx[i].se;
    for (int i = 1; i <= w; i++)
    {
        int x,y; cin >> x >> y;
        f[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (f[i][j]) g[i].emplace_back(j,0.0), g[j].emplace_back(i,0.0);
            else
            {
                double w = hypot(idx[i].fi -  idx[j].fi, idx[i].se - idx[j].se);
                if (w <= m)
                {
                    g[i].emplace_back(j,w);
                    g[j].emplace_back(i,w);
                }
            }
        }
}
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0.0;
    priority_queue <rii, vector<rii>, greater<rii>> q;
    q.push({0.0,s});
    while (q.size())
    {
        rii top = q.top(); q.pop();
        int u = top.se; double kc = top.fi;
        if (kc > d[u]) continue;
        for (iii x : g[u])
        {
            int v = x.fi; double w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
    if (d[n] == inf) cout << -1;
    else printf("%.0lf",d[n]*1000);

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    dijkstra(1);
   /* for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (iii x : g[i]) cout << "(" << x.fi << ',' << x.se << ")";
        cout << '\n';
    }*/

}
