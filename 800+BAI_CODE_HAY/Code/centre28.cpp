#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
const int inf = 1e9;
vector <ii> g[30005];
int n,m;

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
}
void dijkstra(int s, vector <int> &d, vector <int> &cnt)
{
    d[s] = 0; cnt[s] = 1;
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
                d[v] = d[u] + w;
                q.push({d[v],v});
            } else if (d[v] == d[u] + w) cnt[v] += cnt[u];
        }
    }
}
void dfs(int u, vector <int> &d, vector <bool> &us)
{
    us[u] = true;
    for (auto x : g[u])
    {
        int v = x.fi, w = x.se;
        if (d[v] + w == d[u] && us[v] == false) dfs(v, d, us);
    }
}
void solve()
{
    vector <int> d(n + 2, inf), dn(n + 2, inf), cnt(n + 2, 0), cntn(n + 2, 0);
    dijkstra(1, d, cnt);
    dijkstra(n, dn, cntn);
    vector <bool> us(n + 2, false);
    dfs(n, d, us);
    vector <int> vec;
    for (int i = 1; i <= n; i++)
    {
        if (us[i] == false) vec.push_back(i);
        else if (cntn[i]*cnt[i] != cnt[n]) vec.push_back(i);
    }
    cout << vec.size() << '\n';
    for (int x : vec) cout << x << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
