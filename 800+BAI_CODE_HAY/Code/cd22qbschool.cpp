#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;

vector <ii> g[5555];
int d[5555], cnt[5555];


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int type,u,v,w; cin >> type >> u >> v >> w;
        g[u].emplace_back(v,w);
        if (type == 2) g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[1] = 0;
    cnt[1] = 1;
    priority_queue <ii, vector<ii> , greater<ii>> q;
    q.push({0,1});
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
                cnt[v] = cnt[u];
                d[v] = d[u] + w;
                q.push({d[v], v});
            } else if (d[u] + w == d[v]) cnt[v] += cnt[u];
        }
    }
    cout << d[n] << ' ' << cnt[n];


}
