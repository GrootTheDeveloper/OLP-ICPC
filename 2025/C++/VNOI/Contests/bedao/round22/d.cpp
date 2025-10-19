#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1e5;
const int oo = 1e18;
vector<pair<int,int>> adj[100005];
int dijkstra(int n, int start, int target) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    vector<int> dist(n + 5, oo);
    vector<bool> visited(n + 5, false);

    dist[start] = 0;
    while(pq.empty() == false) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u] == true) continue;
        visited[u] = true;
        if (u == target) return d;
        for (auto [v, w] : adj[u]) {
            int newDist = d + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    return dist[target];
    
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q; cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while (q--) {
        int u, v; cin >> u >> v;
        int ans = dijkstra(n, u,v);
        cout << ans << endl;
    }
}