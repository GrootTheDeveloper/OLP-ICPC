#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
const int maxn = 100 + 5;
const int inf = 1e9;
int n,m,k;
vector <ii> g[maxn];

void inp()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
}

void dijkstra(int &type, int &s, int &t)
{
    vector <int> d(n + 1, inf);
    vector <int> par(n + 1, 0);
    d[s] = 0;
    priority_queue <ii, vector<ii>, greater<ii>> q;
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
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }
    if (type == 0) return cout << d[t] << '\n', void();
    vector <int> vec;

    while (t != 0)
    {
        vec.push_back(t);
        t = par[t];
    }
    reverse(vec.begin(), vec.end());
    cout << vec.size() << ' '; for (int c : vec) cout << c << ' '; cout << '\n';
}
void solve()
{
    for (int type, u, v; k--;)
    {
        cin >> type >> u >> v;
        dijkstra(type, u, v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
