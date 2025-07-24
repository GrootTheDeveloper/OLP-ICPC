#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
const int N = 2e5 + 5;
int root, n, k;
vector <ii> g[N];
int d[N], h[N], sz[N];
bool del[N];
void calc_size(int u, int p = 0)
{
    sz[u] = 1;
    for (auto x : g[u])
    {
        int v = x.fi;
        if (v == p || del[v]) continue;
        calc_size(v, u);
        sz[u] += sz[v];
    }
}
int get(int u, int p, int n)
{
    for (auto x : g[u])
    {
        int v = x.fi;
        if (v != p && !del[v] && sz[v] >= n / 2)
            return get(v, u, n);
    }
    return u;
}

void update(int u, int p, unordered_map <int,int> &dp)
{
    if (d[u] > k) return;
    if (dp.find(d[u]) == dp.end()) dp[d[u]] = h[u];
    else dp[d[u]] = min(dp[d[u]], h[u]);

    for (auto x : g[u]) if(!del[x.fi] && x.fi != p)
        update(x.fi, u, dp);
}
void dfs(int u, int &ans, unordered_map <int,int> &dp, int p)
{
    for (auto x : g[u]) if (x.fi != p && !del[x.fi])
    {
        int v = x.fi, w = x.se;
        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        if (d[v] <= k)
        {
            if (d[v] == k) ans = min(ans, h[v]);
            else if (dp.find(k - d[v]) != dp.end()) ans = min(ans, h[v] + dp[k - d[v]]);
            dfs(v, ans, dp, u);
        }
        if (u == root)
            update(v, u, dp);
    }
}
int calc(int u)
{
    int ans = inf;
    unordered_map <int,int> dp;
    calc_size(u);
    root = get(u, 0, sz[u]);
    d[root] = h[root] = 0;
    dfs(root, ans, dp, 0);
    del[root] = true;
    for (auto x : g[root])
        if (!del[x.fi]) ans = min(ans, calc(x.fi));
   // cout << ans << ' ';
    return ans;

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int ans = calc(1);
    cout << (ans == inf? -1 : ans);
}
