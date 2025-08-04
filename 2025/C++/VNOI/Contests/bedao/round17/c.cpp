#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    // dp[i] : số kẹo tối đa FireGhost lấy được khi thùng còn i viên kẹo
    /*
    10 3
    1 3 4

    dp[0] = 0
    dp[1] = 1 | 0
    dp[2] = 1 | 1
    dp[3] = 3 | 0
    dp[4] = 4 | 0
    dp[5] = 4 | 1
    dp[6] = 4 + 1 | 1
    dp[7] = 4 | 3
    dp[8] = 4 | 4
    dp[9] = 4 + 1 | 4
    dp[10] = 3 + 3 | 4 
    */

    int candy, n; cin >> candy >> n;
    vector<int> box(n + 1);
    for (int i = 1; i <= n; i++) cin >> box[i];
    vector<int> dp(candy + 1, 0);

    for (int i = 1; i <= candy; i++) {
        
        for (int j = 1; j <= n; j++) {
            if (i - box[j] >= 0)  
                dp[i] = max(dp[i], i - dp[i - box[j]]);
        }
    }

    cout << dp[candy];
}