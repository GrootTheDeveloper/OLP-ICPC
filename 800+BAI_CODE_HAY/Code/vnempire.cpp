#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

struct DSU
{
    vector <int> par, sz;
    DSU(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    bool Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
const int maxn = 1e5 + 3;
ii a[maxn], b[maxn], c[maxn];
pair<int,pair<int,int>> g[maxn * 3];


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> b[i].fi >> c[i].fi;
        a[i].se = b[i].se = c[i].se = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    int d = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        g[++d] = {abs(a[i].fi - a[i+1].fi),{a[i].se,a[i+1].se}};
        g[++d] = {abs(b[i].fi - b[i+1].fi),{b[i].se,b[i+1].se}};
        g[++d] = {abs(c[i].fi - c[i+1].fi),{c[i].se,c[i+1].se}};
    }
    sort(g + 1, g + d + 1);
    int res = 0;
    DSU dsu(n);
    for (int i = 1; i <= d; i++)
    {
        int x = g[i].se.fi, y = g[i].se.se, w = g[i].fi;
        if (dsu.Union(x,y)) res += w;
    }
    cout << res;
}
