#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int INF = 1e9;

int d[200005][11];
vector<ii> g[200005];
bool stacks[200005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }   

    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 10; j++)
        d[i][j] = INF;

    d[1][0] = 0;
    queue<int> q;
    q.push(1);
    stacks[1] = true;
    while (q.size())
    {
        int u = q.front(); q.pop(); stacks[u] = false;
        for (ii &tmp : g[u])
        {
            int v = tmp.fi, w = tmp.se;
            bool mask = false;
            if (d[v][w] > d[u][0])
                    d[v][w] = d[u][0], mask = true;
            for (int i = 1; i <= 10; i++)
                if (d[v][0] > d[u][i] + i * w)
                    d[v][0] = d[u][i] + i * w, mask = true;
            if (mask && !stacks[v]) q.push(v);
        }
    }
    cout << (d[n][0] == INF? -1 : d[n][0]);
}