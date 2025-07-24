#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int n, x, k, dp[100005], a[100005];
vector <int> g[100005];
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b&1) res = res * a % mode;
        a = a * a % mode;
        b >>= 1;
    }
    return res;
}
void dfs(int u, int p = 0)
{
    dp[u] = a[u];
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        dp[u] ^= dp[v];
    }
    k += (dp[u] == 0);
}
void sub1()
{
    dfs(1);
    cout << power(2, k - (dp[1] == 0));
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (x == 0) sub1();
}
