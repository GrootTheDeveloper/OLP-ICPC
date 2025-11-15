int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<pair<int,int>> edges(m);
    vector<vector<pair<int,int>>> g(n+1); // (to, edge_id)
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    // Tarjan to find bridges
    vector<int> tin(n+1, -1), low(n+1, -1);
    vector<char> is_bridge(m, 0);
    int timer = 0;

    function<void(int,int)> dfs = [&](int u, int pe) {
        tin[u] = low[u] = timer++;
        for (auto [v, id] : g[u]) {
            if (id == pe) continue;
            if (tin[v] != -1) {
                // back-edge
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) is_bridge[id] = 1;
            }
        }
    };

    // Graph is connected per statement, but keep general
    for (int i = 1; i <= n; ++i)
        if (tin[i] == -1) dfs(i, -1);

    // Count sizes in the forest formed by only bridge edges
    vector<char> vis(n+1, 0);
    function<int(int)> dfs2 = [&](int u) {
        vis[u] = 1;
        int sz = 1;
        for (auto [v, id] : g[u]) {
            if (!is_bridge[id]) continue; // only traverse bridges
            if (!vis[v]) sz += dfs2(v);
        }
        return sz;
    };

    ll ans = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        int sz = dfs2(i);              // component size in bridge-only forest
        ans += 1LL * sz * (sz - 1) / 2; // choose any pair inside
    }

    cout << ans << '\n';
    return 0;
}
