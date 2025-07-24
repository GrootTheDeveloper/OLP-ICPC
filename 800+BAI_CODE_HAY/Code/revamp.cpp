#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int inf = 1e15;
vector <vector<ii>> g;
vector <vector<int>> d;
int n, m, k;



void inp()
{
    cin >> n >> m >> k;
    g.assign(n + 1, vector<ii>());
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
}

void solve()
{
    d.assign(n + 2, vector<int> (k + 2, inf));
    priority_queue <iii, vector <iii>, greater<iii>> q;
    d[1][0] = 0;
    q.push({0,{1,0}});
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int kc = top.fi, u = top.se.fi, num = top.se.se;
        if (kc > d[u][num]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v][num] > d[u][num] + w)
            {
                d[v][num] = d[u][num] + w;
                q.push({d[v][num],{v,num}});
            }
            if (d[v][num + 1] > d[u][num] && num < k)
            {
                d[v][num + 1] = d[u][num];
                q.push({d[v][num + 1],{v,num + 1}});
            }
        }
    }
    int res = inf;
    for (int i = 0; i <= k; i++) res = min(res, d[n][i]);
    cout << res;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
