#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int oo = LLONG_MAX;

signed main() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, oo));
    // dp[u][v] : chieu dai tuyen duong ngan nhat tu u -> v
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][k] == oo) continue;
            for (int j = 1; j <= n; j++) {
                if (dp[k][j] == oo) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        cout << (dp[x][y] == oo ? -1 : dp[x][y]) << endl;
    }
    
}