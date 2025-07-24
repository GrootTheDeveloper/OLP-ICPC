#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e16;
vector <vector<ii>> g;
vector <int> d;
int n, m;
void inp()
{
    cin >> n >> m;
    g.assign(n + 1, vector <ii>());
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
      //  g[y].emplace_back(x,w);
    }
}
void solve()
{
    d.assign(n + 1, inf);
    d[1] = 0;
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
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	inp();
	solve();

}
