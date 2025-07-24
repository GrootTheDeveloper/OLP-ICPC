#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
const int inf = 1e15;
int d[300005];
vector <ii> g[300005];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("COMNET.inp","r",stdin);
    freopen("COMNET.out","w",stdout);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].emplace_back(y,i);
    }
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[1] = 0;
    priority_queue <ii, vector <ii>, greater<ii>> q;
    q.push({0,1});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, mx = top.fi;
        if (mx > d[u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, ti = x.se;
            if (d[v] > max(d[u],ti))
            {
                d[v] = max(d[u],ti);
                q.push({d[v],v});
            }
        }
    }
    if (d[n] == inf) d[n] = -1;
    cout << d[n];
}
