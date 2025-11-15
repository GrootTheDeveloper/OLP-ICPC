int main() {
    int n; int r;
    if (!(cin >> n >> r)) return 0;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    deque<pair<int,int>> dq;

    // Multi-source BFS from all storms 'X'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'X') {
                dist[i][j] = 0;
                dq.emplace_back(i, j);
            }
        }
    }

    int di[4] = {1,-1,0,0};
    int dj[4] = {0,0,1,-1};

    while (!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();
        int nd = dist[x][y] + 1;
        if (nd > r) continue; // farther than r is irrelevant for marking
        for (int t = 0; t < 4; ++t) {
            int nx = x + di[t], ny = y + dj[t];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] <= nd) continue;
            dist[nx][ny] = nd;
            dq.emplace_back(nx, ny);
        }
    }

    // Build safe mask: safe if originally '.' and dist > r (or no storm -> INF)
    vector<vector<char>> safe(n, vector<char>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == '.' && dist[i][j] > r) safe[i][j] = 1;

    // Count connected components (4-neighbors) on safe cells
    vector<vector<char>> vis(n, vector<char>(n, 0));
    auto bfs = [&](int si, int sj) {
        queue<pair<int,int>> q;
        vis[si][sj] = 1;
        q.emplace(si, sj);
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int t = 0; t < 4; ++t) {
                int nx = x + di[t], ny = y + dj[t];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (!safe[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    };

    long long components = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (safe[i][j] && !vis[i][j]) {
                ++components;
                bfs(i, j);
            }

    cout << components << '\n';
    return 0;
}
