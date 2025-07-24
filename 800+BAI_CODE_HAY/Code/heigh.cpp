#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second


struct DSU
{
    vector <int> par,sz;
    DSU(int n)
    {
        par.resize(n + 1); sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i]  = 1;
        }
    }
    int find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
    }
};


pair<int,ii> g[100005];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("height.inp","r",stdin);
    freopen("height.out","w",stdout);
    int n,m,s,t; cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[i] = {w,{x,y}};
    }
    sort(g + 1, g + m + 1);
    DSU d(n);
    for (int i = m; i >= 1; i--)
    {
        d.Union(g[i].se.fi, g[i].se.se);
        if (d.find(s) == d.find(t)) return cout << g[i].fi, 0;
    }

}

