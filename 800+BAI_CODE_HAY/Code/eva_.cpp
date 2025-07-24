#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[100005];
int d[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) d[i] = inf;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    for (int i = 1; i <= k; i++)
    {
        int x; cin >> x;
        d[x] = 0;
        q.push({0, x});
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
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
                q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';

}
