#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
vector<int> parent(MAXN, 0);
int n, m;
int start_node; 
bool found = false;

void dfs(int u, int p) {
    if (found) return;
    visited[u] = true;
    parent[u] = p;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
        }
        else if (v != p && !found) {
            found = true;
            start_node = v;
            parent[v] = u;
            return;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            if (found) break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        int v = start_node;
        path.push_back(v);
        int u = parent[v];
        while (u != start_node) {
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(start_node); 


        cout << path.size() << endl;
        for (auto x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
}
