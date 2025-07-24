#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int oo = 1e9 + 7;
// dp[u][0] : to mau den dinh u --> cac con cua u ko to den
// dp[u][1] : ko to den dinh u --> cac con cua u to den
vector<int> adj[100005];
vector<vector<int>> dp(100005, vector<int>(2, -oo));

void dfs(int u, int parent) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] + dp[v][1];
        dp[u][1] += max(dp[v][0], dp[v][1]);
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
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans;
}