#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<pair<int,int>> adj[200005];
vector<int> visited(200005, 0);
const int oo = LLONG_MAX;
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    //    adj[v].push_back({u, w});
    }
    vector<int> dist(n + 1, oo);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 1});
    while (q.empty() == false) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }       
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}