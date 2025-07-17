#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[200005];
vector<int> visited(200005, 0);

void dfs(int u, int parent) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (visited[v] == 1) {
            if (v != parent) {
                cout << "YES";
                exit(0);
            }
        }
        else if (visited[v] == 0) {
            dfs(v, u);
        }
    }
    visited[u] = 2;
}
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, i);
        }
    }
    cout << "NO";
}