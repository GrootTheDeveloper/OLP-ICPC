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

    int cntComponent = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            q.push(i);
            visited[i] = true;
            cntComponent++;
            while (q.empty() == false) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (visited[v] == false) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << cntComponent;
}