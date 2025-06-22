#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18 + 7;

signed main() {
    int q; cin >> q;
    while (q--) {
        int m, n; cin >> m >> n;
        vector<vector<int>> cost(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> cost[i][j];
            }
        }

        vector<vector<vector<int>>> f(m + 1, vector<vector<int>>(n + 1, vector<int>(2, oo)));

        for (int i = 1; i <= m; i++) {
            f[i][0][0] = 0;
        }
        for (int j = 1; j <= n; j++) {
            f[0][j][1] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1] + cost[i][j]);

                f[i][j][1] = min(f[i][j - 1][1], f[i][j - 1][0] + cost[i][j]);
            }
        }
        cout << min(f[m][n][0], f[m][n][1]) << endl;
    }
}