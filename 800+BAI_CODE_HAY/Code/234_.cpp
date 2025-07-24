#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
vector <int> g[100005];
int dp[100005], ans;

void dfs(int u, int p = 0)
{
    dp[u] = 1;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        dp[u] = (dp[u] + dp[u] * dp[v]) % mode;
    }
    ans = (ans + dp[u]) % mode;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ans;
}
