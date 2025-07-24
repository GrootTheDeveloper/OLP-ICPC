#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second


struct DSU
{
    vector <int> par, sz;
    DSU (int n)
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

iii g[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    DSU d(n);
    for (int i = 1; i <= m; i++)
        cin >> g[i].se.fi >> g[i].se.se >> g[i].fi;
    sort(g + 1, g + m + 1);
    int res = 0;
    for (int i = 1; i <= m; i++) if (d.Union(g[i].se.fi, g[i].se.se)) res += g[i].fi;
    cout << res;
}












