#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU
{
    vector<int> par, sz;
    DSU (int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i]  = 1;
        }
    }
    int find(int v)
    {
        return (v == par[v] ? v : par[v] = find(par[v]));
    }
    void join(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
    bool check(int a, int b)
    {
        return find(a) == find(b);
    }
};
int ans[100005];
set <int> s[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int a,b; cin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
    }
    DSU d(n);
    for (int i = 1; i <= k; i++)
    {
        int u,v; cin >> u >> v;
        d.join(u, v);
    }
    int q; cin >> q;
    while (q--)
    {
        char type; cin >> type;
        if (type == '?')
        {
            int u; cin >> u;
            for (auto it = s[u].begin(); it != s[u].end();)
            {
                if (d.check(*it, u))
                {
                    ans[u]++;
                    ans[*it]++;
                    s[*it].erase(u);
                    it = s[u].erase(it);
                }
                else it++;
            }
            cout << ans[u] << '\n';
        }
        if (type == 'F')
        {
            int a,b; cin >> a >> b;
            s[a].insert(b);
            s[b].insert(a);
        }
        if (type == 'T')
        {
            int u,v; cin >> u >> v;
            d.join(u, v);
        }
    }


}
