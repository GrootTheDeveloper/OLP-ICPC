#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
struct DSU
{
    vector <int> par, sz;
    DSU (int n)
    {
        par.resize(n + 4);
        sz.resize(n + 4);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v)
    {
        return ((v == par[v]) ? v : par[v] = find(par[v]));
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
    }
    int calc(int v)
    {
        v = find(v);
        return sz[v];
    }
};
int ans[100005];
ii cas[100005], eg[100005];
bool Ok[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,q; cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> eg[i].fi >> eg[i].se;
    for (int i = 1; i <= q; i++)
    {
        cin >> cas[i].fi >> cas[i].se;
        Ok[cas[i].fi] = true;
    }
    DSU d(n);
    for (int i = 1; i <= m; i++) if (!Ok[i]) d.Union(eg[i].fi, eg[i].se);
    for (int i = q; i >= 1; i--)
    {
        ans[i] = d.calc(cas[i].se);
        d.Union(eg[cas[i].fi].fi, eg[cas[i].fi].se);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';


}
