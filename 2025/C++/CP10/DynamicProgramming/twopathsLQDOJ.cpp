#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mod = 1e9 + 7;
const int N = 100;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {   
         for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int dp[10][10][10][10];

    
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= m; y2++) {
                    dp[x1][y1][x2][y2] = -1;
                }
            }
        }
    }

    dp[1][1][1][1] = 0;

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= m; y2++) {
                    if (x1 + y1 != x2 + y2) continue;
                    if (x1 == 1 && x2 == 1 && y1 == 1 && y2 == 1) continue;
                    if (dp[x1][y1][x2][y2] != -1) continue;

                    int best[4] = {-mod, -mod, -mod, -mod};
                    if (x1 - 1 > 0) {
                        best[0] = dp[x1-1][y1][x2][y2];
                    }
                    if (y1 - 1 > 0) {
                        best[1] = dp[x1][y1-1][x2][y2];
                    }
                    if (x2 - 1 > 0) {
                        best[2] = dp[x1][y1][x2-1][y2];
                    }
                    if (y2 - 1 > 0) {
                        best[3] = dp[x1][y1][x2][y2-1];
                    }
                    cout << a[x1][y1] << "  " << a[x2][y2] << endl;
                    dp[x1][y1][x2][y2] = max({best[0], best[1], best[2], best[3]}) + a[x1][y1] + a[x2][y2];
                    //cout << dp[x1][y1][x2][y2] << endl;
                }
            }
        }
    }
    cout << dp[n][m][n][m];
}