#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TASK "netw"
#define ii pair<int,int>
const int mode = 998244353, MODE = mode * mode;
vector <ii> g[100005];
int d[100005], up[5005][14], low[5005][14];
int n;
void dfs(int u, int p = 0, int w = INT_MAX)
{
    up[u][0] = p;
    low[u][0] = w;

    for (int i = 1; i <= 13; i++)
    {
        low[u][i] = min(low[u][i - 1], low[up[u][i - 1]][i - 1]);
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (ii x : g[u])
    {
        int v = x.first, w = x.second;
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, w);
    }

}

ii lca(int u, int v)
{
    int res =  1e9 + 7;
    if (d[u] > d[v]) swap(u, v);
    int k = d[v] - d[u];
    for (int i = 13; i >= 0; i--)
        if (k >> i & 1)
        {
            res = min(res, low[v][i]);
            v = up[v][i];
        }
    if (u == v) return {res, u};
    for (int i = 13; i >= 0; --i)
        if (up[u][i] != up[v][i])
        {
            res = min({res, low[u][i], low[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    res = min({res, low[u][0], low[v][0]});
    return {res, up[u][0]};

}
int ans[5555];
void sub1()
{
    dfs(1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            ii x = lca(i, j);
            int len = d[i] + d[j] - 2 * d[x.second];
            int res = x.first * len * len;
            ans[i] = (ans[i] + res) % mode;
            ans[j] = (ans[j] + res) % mode;
        }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

}

bool check_sub2()
{
    for (int i = 1; i <= n; i++) 
        for (auto x : g[i]) if (abs(x.first - i) != 1) return false;
    return true;
}

int Arr[100005], cur = 0;
void DFS(int u, int p = 0)
{
    for (auto x : g[u])
        {
            int v = x.first, w = x.second;
            if (v == p) continue;
            Arr[++cur] = w;
        DFS(v, u);
    }
}

int sum_lp[100005];
void init()
{
    for (int i = 1; i <= 1e5; i++)
        sum_lp[i] = (sum_lp[i - 1] + i * i) % mode;
}
int get(int l, int r)
{
    if (r == 0) return 0;
    return (sum_lp[r] - sum_lp[l - 1] + MODE) % mode;
}
int lef[100005], rig[100005];
void sub2()
{
    DFS(1);
    init();
    for (int i = 1; i <= n; i++)
    {
        lef[i] = i - 1;
        if (Arr[i - 1] == 2) lef[i] = lef[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        rig[i] = i + 1;
        if (Arr[i] == 2) rig[i] = rig[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        ans += 2 * get(1, i - lef[i] - 1);
        ans %= mode;
        if (lef[i]) ans += get(i - lef[i], i - 1);
        ans %= mode;

        ans += 2 * get(1, rig[i] - i - 1);
        ans %= mode;
        if (rig[i] != n + 1) ans += get(rig[i] - i, n - i);
        ans %= mode;
        cout << ans << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
   if (n <= 5000) sub1();
   else if (check_sub2()) sub2();
   // sub1(); cout << '\n'; sub2();
}
