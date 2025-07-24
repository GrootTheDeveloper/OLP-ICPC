#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define F first
#define S second
const int N = 1e5 + 5;
const int mode = 1e9 + 7;
vector <int> g[N];
int n, k, h;
ii dp[100005][6];
void dfs(int u, int p = 0)
{
    for (int i = 0; i <= g[u].size(); i++) dp[u][i].F = 1;
    for (int v : g[u])
    {
        if (v != p) dfs(v, u);
        for (int j = 0; j <= min(k, g[v].size()); j++)
        {
            dp[u][0].F = (dp[u][0].F + dp[u][0].F * dp[v][j].F) % mode;
        }
        for (int i = 0; i <= k; i++)
        {

            for (int j = 0; j <= k; j++)
            {
                dp[u][i].F = (dp[u][i].F + dp[u][i - 1].F * dp[v][j - 1].F)%mode;
                dp[u][i].S = max(dp[u][i].F, dp[v][j].F);
                if (dp[v][j].S + 1 <= h)
                {
                    dp[u][i].F = (dp[u][i].F * dp[v][j].F) % mode;
                    dp[u][i].S = max(dp[u][i].S, dp[v][j].S + 1);
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h = (int)log2(n);
    dfs(1);
    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = (ans + dp[1][i].F) % mode;
    cout << ans;
}
