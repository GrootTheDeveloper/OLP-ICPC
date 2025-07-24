#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define val first
#define id second

struct DSU
{
    vector <int> par, sz;
    int maxsize = 0;
    DSU (int n)
    {
        par.assign(n + 3, 0);
        sz.assign(n + 3, 0);

    }
    void add(int v)
    {
        if (par[v] == 0) par[v] = v;
        sz[v] = 1;
        maxsize = max(maxsize, 1ll);
    }
    int find(int v)
    {
        return ((v == par[v])? v : par[v] = find(par[v]));
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
        maxsize = max(maxsize, sz[a]);
    }
};

iii eg[100005];
ii  op[100005], a[100005];
int  ans[100005];



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].id = i;
    for (int i = 1; i < n; i++)
        eg[i] = {max(a[i].val,a[i + 1].val), {i, i + 1}};
    for (int i = 1; i <= q; i++) cin >> op[i].fi, op[i].se = i;
    sort(op + 1, op + q + 1);
    sort(eg + 1, eg + n);
    sort(a + 1, a + n + 1);
    int l = 1, id = 1;
    DSU d(n);
    for (int i = 1; i <= q; i++)
    {
        while (a[id].val <= op[i].fi && id <= n) d.add(a[id].id), id++;
        while (eg[l].fi <= op[i].fi && l < n)
        {
            d.Union(eg[l].se.fi, eg[l].se.se);
            l++;
        }
        ans[op[i].se] = d.maxsize;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
