#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<bool> check(100005, false);
vector<int> parent(100005);
int n, m; 

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    check[1] = true;

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!check[v]) {
                check[v] = true;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    if (!check[n]) {
        cout << "IMPOSSIBLE";
    }
    else {
        int cnt = 0;
        vector<int> path;
        int v = n;
        while (parent[v] != -1) {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(1);
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (auto u : path) {
            cout << u << " ";
        }
    }
}
