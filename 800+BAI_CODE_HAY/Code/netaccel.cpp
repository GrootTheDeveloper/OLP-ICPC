#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,double>
#define iii pair<double,pair<int,int>>
#define fi first
#define se second
const double inf = 1e15;
vector <vector<ii>> g;
vector <vector<double>> d;
double pw[11];
int n, m, k;

void inp()
{
    cin >> n >> m >> k;
    g.assign(n + 2, vector <ii> ());
    for (int i = 1; i <= m; i++)
    {
        int x,y; double w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    pw[0] = 1;
    for (int i = 1; i <= 10; i++) pw[i] = pw[i-1] * 2;
}
void solve()
{
    d.assign(n + 2, vector<double> (k + 2, inf));
    d[1][0] = 0;
    priority_queue <iii, vector<iii>, greater<iii>> q;
    q.push({0,{1,0}});
    while (q.size())
    {
        iii top = q.top(); q.pop();
        int u = top.se.fi, num = top.se.se;
        double kc = top.fi;
        if (kc > d[u][num]) continue;
        for (auto x : g[u])
        {
            int v = x.fi; double w = x.se;
            for (int t = 0; t <= k - num; t++)
                if (d[v][t + num] > d[u][num] + w / pw[t])
                {
                    d[v][t + num] = d[u][num] + w / pw[t];
                    q.push({d[v][t + num],{v, t + num}});
                }
        }
    }
    double res = inf;
    for (int i = 0; i <= k; i++) res = min(res, d[n][i]);
    cout << fixed << setprecision(2) << res;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
