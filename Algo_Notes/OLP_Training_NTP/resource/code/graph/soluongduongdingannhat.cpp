#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN = 2e5 + 5;
const int oo = 1e18 + 7;
const int MOD = 1e9 + 7;
vector<pair<int,int>> adj[MAXN];
vector<int> cnt(MAXN, 0); // cnt[u] = số lượng đường đi ngắn nhất từ 1 đến u
vector<int> dist(MAXN, oo);

using Node = pair<int,int>;
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});

    while (pq.empty() == false) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                cnt[v] = cnt[u];
                pq.push({d + w, v});
            }
            else if (dist[v] == d + w) {
                (cnt[v] += cnt[u]) %= MOD;
            }
        }
    }
    cout << cnt[n];
}