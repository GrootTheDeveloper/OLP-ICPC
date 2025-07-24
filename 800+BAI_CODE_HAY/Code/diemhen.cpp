#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[100005];
int d1[100005],d2[100005], n , m, q;

void dijkstra(int s, int* d)
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    d[s] = 0;
    q.push({0,s});
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
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
       // g[v].emplace_back(u,w);
    }
    dijkstra(1, d1);
    dijkstra(n, d2);
    while (q--)
    {
        int a, b; cin >> a >> b;
        int res = 1e18;
        for (int i = 1; i <= n; i++)
            if (d1[i] != inf && d2[i] != inf) res = min(res, d1[i] * a + d2[i] * b);
        cout << res << '\n';
    }
}
