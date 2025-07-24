#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define x first
#define y second

struct DSU
{
    vector <int> par, sz;
    int scc;
    DSU (int n)
    {
        scc = n;
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
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        scc--;
        sz[a] += sz[b];
        par[b] = a;
    }
};

ii eg[100005];
int op[100005], ans[100005];
bool mark[100005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> eg[i].x >> eg[i].y;
    for (int i = 1; i <= q; i++)
    {
        cin >> op[i];
        mark[op[i]] = true;
    }
    DSU d(n);
    for (int i = 1; i <= m; i++) if (!mark[i])
        d.Union(eg[i].x, eg[i].y);
    for (int i = q; i >= 1; i--)
    {
        ans[i] = d.scc;
        d.Union(eg[op[i]].x, eg[op[i]].y);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

}
