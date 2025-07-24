#include <bits/stdc++.h>
using namespace std;
#define int long long


pair <pair<int,int>,int> d[201];
int vs[201];
int last, res;
vector <int> g[201];

double calc( pair<int,int> a, pair<int,int> b)
{
    int x = a.first - b.first, y = a.second - b.second;
    return sqrt(x*x + y*y);
}

void dfs(int u)
{
    if (vs[u] == last) return;
    vs[u] = last;
    res ++;
    for (int v : g[u])
        dfs(v);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("transmission.inp","r",stdin);
    freopen("transmission.out","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        d[i] = {{x,y},w};
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (calc(d[i].first, d[j].first) <= d[i].second) g[i].push_back(j);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        res = 0;
        last = i;
        dfs(i);
        ans = max(ans, res);
    }
    cout << ans;


}
