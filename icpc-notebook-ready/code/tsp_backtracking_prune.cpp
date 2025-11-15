int main() {
    int n; if (!(cin >> n)) return 0;
    vector<vector<long long>> A(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    // global minimum edge cost (exclude self-loops)
    long long gmin = LLONG_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j) gmin = min(gmin, A[i][j]);

    // Pre-sort candidate next nodes for each u by cost A[u][v] ascending
    vector<vector<int>> order(n);
    for (int u = 0; u < n; ++u) {
        order[u].resize(n-1);
        int idx = 0;
        for (int v = 0; v < n; ++v) if (v != u) order[u][idx++] = v;
        sort(order[u].begin(), order[u].end(), [&](int x, int y){
            return A[u][x] < A[u][y];
        });
    }

    const int START = 0;
    long long best = (long long)4e18;

    function<void(int,int,long long)> dfs = [&](int u, int mask, long long cost) {
        int cnt = __builtin_popcount((unsigned)mask);
        // bound: remaining edges = (n - cnt) to visit all + 1 to return
        int remEdges = (n - cnt) + 1;
        if (cost + gmin * remEdges >= best) return;

        if (cnt == n) {
            best = min(best, cost + A[u][START]); // close the tour
            return;
        }
        // try next cities in ascending edge cost
        for (int v : order[u]) {
            if (mask & (1 << v)) continue;
            dfs(v, mask | (1 << v), cost + A[u][v]);
        }
    };

    dfs(START, 1 << START, 0LL);
    cout << best << '\n';
    return 0;
}
