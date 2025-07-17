#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[200005];
vector<int> visited(200005, 0);

signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> group(n + 1, 0);
 //   vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            group[i] = 1;
//            parent[i] = i;
            while (q.empty() == false) {
                auto u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (visited[v] == 1) {
                        if (group[v] == group[u]) {
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                    else if (visited[v] == 0) {
                        visited[v] = 1;
                        q.push(v);
//                        parent[v] = u;
                        group[v] = (group[u] == 1 ? 2 : 1);
                    }
                }
                visited[u] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << group[i]  << " ";
    }
}