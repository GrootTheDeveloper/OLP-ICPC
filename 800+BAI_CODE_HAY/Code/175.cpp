#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15, mode = 1e9 + 7;

vector <ii> g[200005];
int d[200005], cnt[200005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++) d[i] = inf;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0,1});
    d[1] = 0;
    cnt[1] = 1;
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
                cnt[v] = cnt[u];
                q.push({d[v], v});
            } else if (d[v] == d[u] + w) cnt[v] = (cnt[v] + cnt[u]) % mode;
        }
    }
    cout << cnt[n];
}

