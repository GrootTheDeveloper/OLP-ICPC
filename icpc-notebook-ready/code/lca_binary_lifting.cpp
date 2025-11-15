int main() {
    int n, q; if (!(cin >> n >> q)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;

    vector<int> depth(n+1, -1);
    vector<vector<int>> up(LOG, vector<int>(n+1, 1)); // up[k][1] = 1

    // BFS node 1 to get depth and up[0]
    queue<int> qu;
    depth[1] = 0;
    up[0][1] = 1;
    qu.push(1);
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v : g[u]) if (depth[v] == -1) {
            depth[v] = depth[u] + 1;
            up[0][v] = u;
            qu.push(v);
        }
    }
    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }

    auto lift = [&](int u, int d) {
        for (int k = 0; k < LOG; ++k) {
            if (d & (1 << k)) u = up[k][u];
        }
        return u;
    };

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int k = LOG-1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    };
    for (int i = 0; i < q; ++i) {
        int u, v; cin >> u >> v;
        int ans = lca(u, v);
        cout << ans << (i+1==q ? '\n' : ' ');
    }
    return 0;
}
