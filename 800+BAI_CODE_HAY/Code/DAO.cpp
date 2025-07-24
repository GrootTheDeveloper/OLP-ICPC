#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii d[1001];
int n, s, t, f[1001], par[1001];
double m;
vector <int> g[1001];
bool vs[1001];
double calc(ii a, ii b)
{
    return sqrt((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se)) <= m;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("dao.inp","r",stdin);
    freopen("dao.out","w",stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        int x,y; cin >> x >> y;
        d[i] = {x,y};
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        if (calc(d[i],d[j])) g[i].push_back(j), g[j].push_back(i);
    queue <int> q;
    q.push(s);
    vs[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
        {
            if (!vs[v])
            {
                vs[v] = true;
                f[v] = f[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    if (f[t] == 0) return cout << -1,0;
    cout << f[t] - 1<< '\n';
    vector <int> path;
    for (int u = par[t]; u != s; u = par[u]) path.push_back(u);
    reverse(path.begin(), end(path));
    for (int x : path) cout << x << ' ';


}
