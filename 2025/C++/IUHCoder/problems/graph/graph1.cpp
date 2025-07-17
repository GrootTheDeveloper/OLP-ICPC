#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[200005];
vector<bool> visited(200005, false);
void dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    cout << u << ' ';
}
signed main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

}