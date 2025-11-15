const int MOD = 1'000'000'007;
int main() {
    int n, m;    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int,long long>>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<long long> dist(n+1, INF);
    vector<int> ways(n+1, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[1] = 0;
    ways[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du != dist[u]) continue;

        for (auto [v, w] : g[u]) {
            long long nd = du + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            } else if (nd == dist[v]) {
                ways[v] += ways[u];
                if (ways[v] >= MOD) ways[v] -= MOD;
            }
        }
    }

    if (dist[n] >= INF/2) cout << 0 << '\n'; // không có đường đi
    else cout << ways[n] << '\n';
    return 0;
}
