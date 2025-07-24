#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> g[100005], h[100005];
int val[100005], lazy[100005];
int in[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[v]++, in[u]++;
    }
    int S = (int)sqrt(n);
    for (int u = 1; u <= n; u++)
        if (in[u] >= S)
        {
            for (int v : g[u])
                h[v].push_back(u);
        }
    while (q--)
    {
        int kind, u, d; cin >> kind >> u;
        if (kind == 1)
        {
            cin >> d;
            if (in[u] >= S) lazy[u] += d;
            else for (int v : g[u]) val[v] += d;
        }
        if (kind == 2)
        {
            int ans = val[u];
            for (int v : h[u]) ans += lazy[v];
            cout << ans << '\n';
        }
    }
}
