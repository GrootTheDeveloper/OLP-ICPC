#include <bits/stdc++.h>
using namespace std;
#define int long long
#define iii pair<int,pair<int,int>>
#define fi first
#define se second

struct DSU
{
    vector <int> par, sz;
    DSU(int n)
    {
        par.assign(n + 1, 0);
        sz.assign( n + 1, 1);
        for (int i = 1; i <= n; i++) par[i] = i;
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
int n, p;
iii g[100004];
int t[10004];
int low = INT_MAX;

void inp()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> t[i], low = min(low, t[i]);
    for (int i = 1; i <= p; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[i] = {2 * w + t[x] + t[y],{x,y}};
    }
    sort(g + 1, g + p + 1);
}
void solve()
{
    DSU d(n);
    int res = 0;
    for (int i = 1; i <= p; i++)
        if (d.Union(g[i].se.fi, g[i].se.se)) res += g[i].fi;
    cout << res + low;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    solve();
}
