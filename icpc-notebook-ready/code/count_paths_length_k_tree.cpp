int main() {
    int n, K; if (!(cin >> n >> K)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> parent(n+1, 0), order;
    order.reserve(n);
    stack<int> st;
    st.push(1); parent[1] = -1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        order.push_back(u);
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            st.push(v);
        }
    }
    reverse(order.begin(), order.end());

    long long ans = 0;
    vector<vector<long long>> dp(n+1, vector<long long>(K+1, 0));
    for (int u : order) {
        dp[u][0] = 1; // chính u, khoảng cách 0
        for (int v : g[u]) if (v != parent[u]) {
            for (int j = 0; j <= K-1; ++j) {
                int t = K-1-j; // độ sâu trong dp[v] trước khi dịch
                ans += dp[u][j] * dp[v][t];
            }
            for (int d = 1; d <= K; ++d) {
                dp[u][d] += dp[v][d-1];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
