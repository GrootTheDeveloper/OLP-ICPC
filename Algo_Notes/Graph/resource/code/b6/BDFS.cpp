#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m, compCount = 0; 
const int MAXN = 100005;
vector<bool> visited(MAXN, false);
vector <int> adj[MAXN];

void bfs(int s) { 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (visited[v] == false) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    compCount++;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (visited[u] == false) {
            bfs(u);
        }
    }
    cout << compCount;
}