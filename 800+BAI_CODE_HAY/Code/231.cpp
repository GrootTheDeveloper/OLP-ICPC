#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[101][100005], res, d[101], k, n;
vector <int> g[100001];
void dfs(int u, int p = 0)
{
    dp[0][u] = 1;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        for (int i = 1; i <= k; i++)
        {
            d[i] = dp[i - 1][v];
            res += (d[i] * dp[k - i][u]);
        }
        for (int i = 1; i <= k; i++) dp[i][u] += d[i];
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << res;

}
