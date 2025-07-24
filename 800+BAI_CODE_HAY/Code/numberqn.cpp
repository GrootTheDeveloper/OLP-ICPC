#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
vector <int> g[100005];
int d[100005], mode, n, q, par[100005], f[1001][1001];

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b&1) res = (res * a) % mode;
        a = (a * a) % mode;
        b >>= 1;
    }
    return res;
}

void dfs_pre(int u, int p = 0)
{
    for (auto v : g[u])
        if (v != p)
        {
            d[v] = d[u] + 1;
            par[v] = u;
            dfs_pre(v, u);
        }
}
void sub1()
{
    dfs_pre(1);
    while (q--)
    {
        int u, v; cin >> u >> v;
        vector <int> vec1, vec2;
        while (u != v)
        {
            if (d[v] > d[u])
            {
                vec2.push_back(f[v][par[v]]);
                v = par[v];
            }
            else if (d[u] > d[v])
            {
                vec1.push_back(f[u][par[u]]);
                u = par[u];
            } else if (d[u] == d[v])
            {
                vec1.push_back(f[u][par[u]]);
                vec2.push_back(f[v][par[v]]);
                u = par[u]; v = par[v];
            }
        }
        int res = 0;
        for (int x : vec1) res = (res * 10 + x) % mode;
        for (int i = vec2.size() - 1; i >= 0; i--) res = (res * 10 + vec2[i]) % mode;
        cout << res << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> mode;
    for (int i = 1; i < n; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        f[u][v] = f[v][u] = w;
    }
    cin >> q;
    if (n <= 1000 && q <= 1000) sub1();

}
