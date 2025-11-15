static const long long MOD = 1'000'000'007LL;
int main() {
    int n;     if (!(cin >> n)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    // Iterative DFS to get parent and postorder
    vector<int> parent(n+1, 0), order; order.reserve(n);
    stack<int> st; st.push(1); parent[1] = -1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        order.push_back(u);
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            st.push(v);
        }
    }
    vector<long long> dp(n+1, 1); // initialize dp[u]=1 (leaf -> 1)
    // process in reverse (postorder)
    for (int idx = (int)order.size()-1; idx >= 0; --idx) {
        int u = order[idx];
        long long ways = 1;
        for (int v : g[u]) if (v != parent[u]) {
            ways = (ways * (1 + dp[v]) ) % MOD;
        }
        dp[u] = ways;
    }
    long long ans = 0;
    for (int u = 1; u <= n; ++u) {
        ans += dp[u];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans % MOD << '\n';
    return 0;
}
