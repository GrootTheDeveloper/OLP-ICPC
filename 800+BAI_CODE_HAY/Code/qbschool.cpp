#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second

const int inf = 1e9;
int d[5005], cnt[5005];
vector <ii> g[5005];
int n, m;
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int kind,u,v,w;
        cin >> kind >> u >> v >> w;
        g[u].emplace_back(v,w);
        if (kind == 2) g[v].emplace_back(u,w);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[1] = 0;
    cnt[1] = 1;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0,1});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u]) continue;
        for (ii x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] == d[u] + w) cnt[v] += cnt[u];
            if (d[v] > d[u] + w)
            {
                cnt[v] = cnt[u];
                d[v] = d[u] + w;
                q.push({d[v],v});
            }

        }
    }
    cout << d[n] << ' ' << cnt[n];
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
