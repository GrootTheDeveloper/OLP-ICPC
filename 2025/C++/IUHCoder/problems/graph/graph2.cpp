#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[200005];
vector<bool> visited(200005, false);

signed main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    cout << 1 << " ";
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                cout << v << " ";
            }
        }
    }    

}
