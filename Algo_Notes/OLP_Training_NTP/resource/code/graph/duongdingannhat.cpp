#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[100005];

signed main() {
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    parent[1] = 1;
    visited[1] = true;

    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        if (u == n) break;
        for (auto v : adj[u]) {
            if (visited[v] == false) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    int u = n;
    vector<int> ans;
    while (parent[u] != u) {
        ans.push_back(u);
        u = parent[u];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << 1 << " ";
    for (auto v : ans) cout << v << " ";
}