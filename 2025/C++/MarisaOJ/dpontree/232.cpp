#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
// dp[u][0] : to mau den dinh u = 0
// dp[u][1] : ...
// dp[u][2] : ... 
vector<int> adj[100005];
vector<vector<int>> dp(100005, vector<int>(3, 0));

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = dp[u][2] = 1;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        (dp[u][0] = dp[u][0] * dp[v][1] + dp[u][0] * dp[v][2]) %= MOD;
        (dp[u][1] = dp[u][1] * dp[v][0] + dp[u][1] * dp[v][2]) %= MOD;
        (dp[u][2] = dp[u][2] * dp[v][0] + dp[u][2] * dp[v][1]) %= MOD;
    }
}

signed main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    dfs(1,1);

    int ans = dp[1][0] + dp[1][1] + dp[1][2];
    ans %= MOD;

    cout << ans;

}