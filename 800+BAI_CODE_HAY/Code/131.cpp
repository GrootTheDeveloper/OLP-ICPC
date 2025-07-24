#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DSU
{
    vector <int> par, sz, num;
    DSU (int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        num.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
            num[i] = i;
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
        par[b] = a;
        sz[a] += sz[b];
        num[a] += num[b];
    }
    int calc(int v)
    {
        v = find(v);
        return num[v];
    }
};
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    DSU d(n);
    while (q--)
    {
        int kind, u,v;
        cin >> kind >> u;
        if (kind == 2) cout << d.calc(u) << '\n';
        else
        {
            cin >> v;
            d.Union(u,v);
        }
    }
}
