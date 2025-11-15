int main() {
    int n, m; if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n), gr(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        gr[v].push_back(u); // reverse edge
    }
    vector<char> vis(n, 0);
    vector<int> order; order.reserve(n);
    for (int s = 0; s < n; ++s) if (!vis[s]) {
        vector<pair<int,int>> st; st.emplace_back(s, 0);
        vis[s] = 1;
        while (!st.empty()) {
            int u = st.back().first;
            int &it = st.back().second;
            if (it < (int)gr[u].size()) {
                int v = gr[u][it++];
                if (!vis[v]) { vis[v] = 1; st.emplace_back(v, 0); }
            } else {
                order.push_back(u);
                st.pop_back();
            }
        }
    }
    int c = order.back(); 
    auto bfs = [&](const vector<vector<int>>& GG, int start) {
        vector<char> seen(n, 0);
        queue<int> q; q.push(start); seen[start] = 1;
        int cnt = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : GG[u]) if (!seen[v]) {
                seen[v] = 1; q.push(v); ++cnt;
            }
        }
        return pair<vector<char>,int>(move(seen), cnt);
    };

    auto [reach_in_GR, cnt_all] = bfs(gr, c);
    if (cnt_all != n) {
        cout << 0 << '\n';
        return 0;
    }
    auto [reach_from_c_in_G, _1]  = bfs(g,  c);
    long long scc_size = 0;
    for (int i = 0; i < n; ++i)
        if (reach_from_c_in_G[i] && reach_in_GR[i]) ++scc_size;

    cout << scc_size << '\n';
    return 0;
}
