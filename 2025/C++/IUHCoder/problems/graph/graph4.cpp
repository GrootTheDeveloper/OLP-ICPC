#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[200005];
vector<bool> visited(200005, false);

signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>dp(200005, 21112005);
    queue<int> q;
    q.push(1);
    dp[1] = 1;
    visited[1] = true;
    while (q.empty() == false) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
                dp[v] = dp[u] + 1; 
            }
        }
    }
    if (dp[n] == 21112005) cout << "IMPOSSIBLE"; else cout << dp[n];
}