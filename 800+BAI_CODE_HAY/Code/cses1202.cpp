#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e16, mode = 1e9 + 7;

vector <ii> g[100005];
int d[100005], f_high[100005], f_low[100005], cnt[100005];
int n, m;
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++) d[i] = f_low[i] = inf;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    d[1] = 0;
    f_high[1] = f_low[1] = 0;
    cnt[1] = 1;
    q.push({0,1});
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
                f_low[v] = f_low[u] + 1;
                f_high[v] = f_high[u] + 1;
                q.push({d[v],v});
            }
            else if (d[v] == d[u] + w)
            {
                f_high[v] = max(f_high[u] + 1, f_high[v]);
                f_low[v]  = min(f_low[u]  + 1, f_low[v] );
                cnt[v] = (cnt[v] + cnt[u]) % mode;
            }
        }
    }
    cout << d[n] << ' ' << cnt[n] << ' ' << f_low[n] << ' ' << f_high[n];
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
