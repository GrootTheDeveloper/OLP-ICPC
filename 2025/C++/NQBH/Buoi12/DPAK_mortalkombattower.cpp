#include <bits/stdc++.h>
#define int long long
const int oo = 1e18 + 7;
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, oo));

        if (n == 1) {
            //cout << "\n" << "OUTPUT:" << (a[1] == 1) << endl;
            cout << (a[1] == 1) << endl;
            continue;    
        }
        if (n == 2) {
            //cout << "\n" << "OUTPUT:" << (a[1] == 1 ? 1 : 0) << endl;
            cout << (a[1] == 1 ? 1: 0) << endl;
            continue;
        }
        /*
        dp[i][0] : số skip point nhỏ nhất khi đến lượt bạn chơi ở i
        dp[i][1] : số skip point nhỏ nhất khi đến lượt mình chơi ở i
        */

        dp[1][0] = (a[1] == 1 ? 1 : 0);
        dp[2][0] = (a[1] == 1) + (a[2] == 1);


        dp[2][1] = dp[1][0];
        dp[3][0] = min(dp[2][1] + (a[3] == 1), dp[1][1] + (a[2] == 1) + (a[3] == 1));
        dp[3][1] = min(dp[2][0], dp[1][0]);
        for (int i = 4; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1] + (a[i] == 1), dp[i - 2][1] + (a[i] == 1) + (a[i - 1] == 1));
            dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        }

        cout  << min(dp[n][0], dp[n][1]) << endl;
    }
}