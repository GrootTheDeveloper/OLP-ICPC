#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e12;
int k, n, m;
int a[100005];
vector <int> g[100005];

void bfs(int s, vector <int> &d)
{
    d[s] = 0;
    vector <bool> vs(n + 1, false);
    vs[s] = true;
    queue <int> q; q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!vs[v])
        {
            vs[v] = true;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> d(n + 2, inf);
    bfs(n, d);
    for (int i = 1; i <= k; i++) cout << d[a[i]] << ' ';
}

