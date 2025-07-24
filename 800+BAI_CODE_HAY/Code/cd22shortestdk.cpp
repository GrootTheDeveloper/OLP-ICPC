#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e12;
int d[100005][20];
vector <ii> g[100005];
bool mark[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + k + 1, inf);
    for (int i = 0; i <= k; i++) d[1][i] = 0;

    queue <ii> q;
    q.push({1, 0});
    mark[1] = true;
    while (q.size())
    {
        ii x = q.front(); q.pop();
        int u = x.fi, p = x.se;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (v == p) continue;
            if (!mark[v])
            {
                d[v][0] = d[u][0] + w;
                for (int i = 1; i <= k; i++)
                    d[v][i] = min(d[u][i] + w, d[u][i - 1]);
                mark[v] = true;
                q.push({v, u});
            } else
            {
                bool msk = false;
                if (d[v][0] > d[u][0] + w) {msk = true; d[v][0] = d[u][0] + w;}
                for (int i = 1; i <= k; i++)
                {
                    int x = d[v][i];
                    d[v][i] = min({d[v][i], d[u][i] + w, d[u][i - 1]});
                    if (x != d[v][i]) msk = true;
                }
                if (msk) q.push({v, u});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i][k] << ' ';

}