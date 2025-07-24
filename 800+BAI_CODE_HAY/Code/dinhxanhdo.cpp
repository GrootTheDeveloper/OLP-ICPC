#include <bits/stdc++.h>
using namespace std;
#define int long long
int sz[200005], dp[200005];
vector <int> g[200005];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += sz[v];
        sz[u] += sz[v];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int u = 2; u <= n; u++)
    {
        int v; cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    sort(dp + 1, dp + n + 1);
    for (int i = 1; i <= n; i++) dp[i] += dp[i - 1];
    for (int i = 0; i <= n; i++) cout << dp[i] << ' ';

}
