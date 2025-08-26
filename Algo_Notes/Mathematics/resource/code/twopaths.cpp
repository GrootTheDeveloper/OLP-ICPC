#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<vector<int>>> f(n + m, vector<vector<int>>(n + 1, vector<int>(n + 1, -oo)));

    f[0][1][1] = 0;

    for (int step = 1; step <= n + m - 2; step++) {
        for (int x1 = 1; x1 <= n; x1++) {
            int y1 = step - x1 + 2;
            if (y1 <= 0 || y1 > m) continue;
            for (int x2 = 1; x2 <= n; x2++) {
                int y2 = step - x2 + 2;
                if (y2 <= 0 || y2 > m) continue;

                int val = -oo;
                val = max(val, f[step - 1][x1 - 1][x2]);
                val = max(val, f[step - 1][x1][x2 - 1]);
                val = max(val, f[step - 1][x1 - 1][x2 - 1]);
                val = max(val, f[step - 1][x1][x2]); 


                if (x1 == x2 && y1 == y2 && (x1 != n || y1 != m)) continue;

                if (x1 == x2 && y1 == y2)
                    val += a[x1][y1];
                else
                    val += a[x1][y1] + a[x2][y2];
                f[step][x1][x2] = val;
            }
        }
    }
    cout << f[n + m - 2][n][n];
}
