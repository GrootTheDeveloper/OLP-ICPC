#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e12;
int a, b, n, m;
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
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> d1(n + 1, inf), d2(n + 1, inf);
    bfs(a, d1);
    bfs(b, d2);
    int res = 0;
    for (int i = 1; i <= n; i++) res += (d1[i] <= d2[i] && d1[i] != inf);
    cout << res;
}
