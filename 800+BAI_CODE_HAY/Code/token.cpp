#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[3][200005];
vector <int> g[200005];
void dfs(int u)
{
    for (int v : g[u])
    {
        dfs(v);
        dp[1][u] += (dp[1][v] + dp[2][v]);
        dp[2][u] += dp[2][v];
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int v; cin >> v;
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) dp[1][i] = dp[2][i] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) cout << dp[1][i] << ' ';
}
