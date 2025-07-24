#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 9;
const int N = 2e5;
int a[N], b[N], d[N], up[N][18];
int n;
vector<int> g[N];

void dfs(int u, int p = 0)
{
    up[u][0] = p;
    for (int i = 1; i <= 17; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int lift(int k, int v)
{
    for (int i = 17; i >= 0; i--)
        if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    v = lift(d[v] - d[u], v);
    if (v == u) return u;
    for (int i = 17; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
void sub1()
{
    dfs(1);
    int MASK = (1 << n) - 1;
    int res = 0;
    for (int mask = 1; mask <= MASK; mask++)
    {
        int R = 0;
        int ans = 1;
        for (int i = 0; i < n; i++)
        if (mask >> i & 1)
        {
            R = (R == 0? i + 1 : lca(R, i + 1));
            ans = (ans * a[i + 1]) % mode;
        }
        res = (res + ans * b[R]) % mode;
    }
    cout << res << ' ';
}

int ans = 0;
int dp[200005], f[200005];
void calc(int u, int p = 0)
{
    dp[u] = 1 + a[u];
    int k = 1;
    for (int v : g[u])
    if (v != p)
    {
        calc(v, u);
        dp[u] = dp[u] * dp[v] % mode;
        k = (k + dp[v]) % mode;
    }
    ans = (ans + (dp[u] - k + mode) * b[u]) % mode;
}

void sub2()
{
    calc(1);
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n <= 20) sub1();
//    else sub2();
  //  sub1(); sub2();
}
