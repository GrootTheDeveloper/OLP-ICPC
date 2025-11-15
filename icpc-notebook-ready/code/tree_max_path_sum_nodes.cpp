int main() {
    int n;     if (!(cin >> n)) return 0;
    vector<long long> A(n+1);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // iterative DFS to avoid stack overflow
    vector<int> parent(n+1, 0), order;
    order.reserve(n);
    stack<int> st;
    st.push(1); parent[1] = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        order.push_back(u);
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            st.push(v);
        }
    }

    vector<long long> down(n+1, LLONG_MIN/4);
    long long ans = LLONG_MIN/4;

    // process nodes in reverse order = postorder
    for (int idx = (int)order.size()-1; idx >= 0; --idx) {
        int u = order[idx];
        long long best1 = 0, best2 = 0; // top two non-negative child downs
        for (int v : g[u]) if (v != parent[u]) {
            long long c = max(0LL, down[v]);
            if (c > best1) { best2 = best1; best1 = c; }
            else if (c > best2) { best2 = c; }
        }
        down[u] = A[u] + best1;
        long long through = A[u] + best1 + best2;
        ans = max(ans, through);
    }
}
