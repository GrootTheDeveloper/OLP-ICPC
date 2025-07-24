#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
vector <int> g[100005];
int d[100005], par[100005];
bool vs[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue <int> q;
    q.push(1);
    d[1] = 0;
    vs[1] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
        {
            if (!vs[v])
            {
                vs[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
                par[v] = u;
            }
        }
    }
    cout << d[n] << '\n';
    vector <int> vec;
    for (int u = n; u != 0; u = par[u]) vec.push_back(u);
    reverse(begin(vec), end(vec));
    for (int x : vec) cout << x << ' ';
}

