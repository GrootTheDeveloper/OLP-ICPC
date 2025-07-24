#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
vector <ii> g[10005];
int d[10004], cnt[10004];
ii op[500005];
bool cmp(ii a, ii b)
{
    return ((a.fi == b.fi)? a.se < b.se : a.fi < b.fi);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("STABLE.inp","r",stdin);
    freopen("STABLE.OUT","w",stdout);
    int n,m,s; cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        op[i] = {x,y};
    }
    sort(op + 1, op + m +1, cmp);
    g[op[1].fi].emplace_back(op[1].se,1);
    for (int i = 2; i <= m; i++)
    {
        int x = op[i].fi, y = op[i].se;
        if (x != op[i-1].fi || y!=op[i-1].se) g[x].emplace_back(y,1);
    }

    for (int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    cnt[s] = 1;
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
                cnt[v] = cnt[u];
                d[v]   = d[u] + w;
                q.push({d[v],v});
            } else if (d[v] == d[u] + w) cnt[v] += cnt[u];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (i != s && cnt[i] > 1);
    cout << res;

}
