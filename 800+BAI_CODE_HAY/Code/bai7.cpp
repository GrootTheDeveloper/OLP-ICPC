#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

bool mark[maxn];
int a[maxn];
struct DSU
{
    vector <int> par, sz, type;
    DSU (int n)
    {
        par.resize(n + 1); sz.resize(n + 1); type.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i]  = 1;
            type[i]= 0;
        }
    }
    int find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void Union(int u, int v)
    {
        u = find(u); v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u,v);
        par[v] = u;
        sz[u] += sz[v];
    }
    void add(int u, int x)
    {
        u = find(u);
        type[u] = x;
    }
    double calc(int u)
    {
        u = find(u);
        return (double)a[type[u]] / sz[u];
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("pizza.inp","r",stdin);
    freopen("pizza.out","w",stdout);
    int n,m,q; cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    DSU d(n);
    vector <pair<int,int>> op;
    for (int i = 1; i <= q; i++)
    {
        int kind, x, y;
        cin >> kind >> x >> y;
        if (kind == 1) op.emplace_back(x,y);
        else d.Union(x,y);
    }

    set <int> s;
    for (auto x : op)
    {
        s.insert(x.second);
        d.add(x.first, x.second);
    }
    cout << s.size() << '\n';
    cout << fixed << setprecision(8);
    for (int i = 1; i <= n; i++) cout << d.calc(i) << '\n';

}
