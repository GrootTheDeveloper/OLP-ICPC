#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int r, c; cin >> r >> c;

    vector<vector<char>> a(r + 1, vector<char>(c + 1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j] - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int m = i; m <= r; m++) {
                for (int n = j; n <= c; n++) {
                    int check = (m - i + 1) * (n - j + 1);
                    int sumOne = dp[m][n] - dp[i - 1][n] - dp[m][j - 1] + dp[i - 1][j - 1];
                    if (sumOne == check) {
                        ans = max(ans, sumOne);
                    }
                }
            }
        }
    }
    cout << ans;
    /*
    (1,1) (1, 2) (1, 3) (1, 4)
    (2,1) (2, 2) (2, 3) (2, 4)
    (3,1) (3, 2) (3, 3) (3, 4)
    (4,1) (4, 2) (4, 3) (4, 4)
    
    */
}