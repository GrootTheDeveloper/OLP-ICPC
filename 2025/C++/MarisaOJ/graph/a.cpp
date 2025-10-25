#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> adj[100005];
int n, m, a, b;
vector<int> comp;
vector<bool> visited(100005, false);

void dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (visited[v] == false) {
            comp.push_back(v);
            dfs(v);
        }
    }
}

void bfs(int start, vector<int> &dist) {
    queue<int> q;
    q.push(start);
    vector<int> vis(n + 1, false);
    vis[start] = true;
    while (q.empty() == false) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == false) {
                vis[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

signed main() {
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    comp.push_back(a);
    dfs(a);
    bool check = false;
    for (int i : comp) {
        if (i == b) {
            check = true;
            break;
        }
    }
    if (check == false) {
        cout << -1;
        return 0;
    }

    vector<int>distA(n + 1, -1), distB(n + 1, -1);
    distA[a] = 0;
    distB[b] = 0;
    bfs(a, distA);
    bfs(b, distB);

    int ans = 1e18;
    for (auto u : comp) {
        cout << u << " " << distA[u] << " " << distB[u] << endl;
        if (distA[u] == distB[u]) {
            ans = min(ans, distA[u]);
        }
    }
    cout << (ans == 1e18 ? -1 : ans);

}