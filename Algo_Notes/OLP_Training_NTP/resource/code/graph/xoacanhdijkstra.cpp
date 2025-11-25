#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN = 2e5 + 5;
const int oo = 1e18 + 7;

using Node = tuple<int,int,int>; // (d, u, c)

vector<pair<int,int>> adj[MAXN];
vector<vector<int>> dist(MAXN, vector<int>(7, oo));

signed main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (pq.empty() == false) {
        auto [d, u, c] = pq.top(); pq.pop();

        if (d != dist[u][c]) continue;

        for (auto [v, w] : adj[u]) {
            // không dùng lần gán trọng số 0 cho cạnh u->v
            if (dist[v][c] > d + w) {
                dist[v][c] = d + w;
                pq.push({dist[v][c], v, c});
            }
            // nếu mà tôi gán trọng số 0 cho cạnh u-> v
            if (c + 1 <= k && dist[v][c + 1] > d) {
                dist[v][c + 1] = d;
                pq.push({d, v, c + 1});
            }
        }
    }
    int ans = oo;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[n][i]);
    }
    if (ans == oo) { cout << -1; return 0; }
    cout << ans;
}