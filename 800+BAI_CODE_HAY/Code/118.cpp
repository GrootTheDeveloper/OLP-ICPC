#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[200005];
int d[200005];
signed main()
{
    int n,m; cin >> n >> m;
    for (int i = 1; i <= 2e5; i++)
    {
        g[i + 1].push_back(i);
        if (i <= 1e5) g[i].push_back(i * 2);
    }
    vector <bool> vs(200005, false);
    vs[n] = true;
    queue <int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!vs[v])
        {
            d[v] = d[u] + 1;
            vs[v] = true;
            q.push(v);
        }
    }
    cout << d[m];

}
