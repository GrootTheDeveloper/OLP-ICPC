#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;

signed main() {
    int a, b, c;
    /*
    a = 2, b = 3, c = 1
    ABABCB
    */
    cin >> a >> b >> c;
//    int dp[101][101][101][3]; 
    vector<vector<vector<vector<int>>>> dp(a + 1, vector<vector<vector<int>>>(b + 1, vector<vector<int>>(c + 1, vector<int>(3, 0))));
    // dp[i][j][k][l] : số cách chọn i chữ A, j chữ B, k chữ C, kí tự cuối là l
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    for (int A = 0; A <= a; A++) {
        for (int B = 0; B <= b; B++) {
            for (int C = 0; C <= c; C++) {
                if (A + B + C <= 1) continue;
                if (A > 0)
                    (dp[A][B][C][0] = dp[A - 1][B][C][1] + dp[A - 1][B][C][2]) %= mod;
                if (B > 0) 
                    (dp[A][B][C][1] = dp[A][B - 1][C][0] + dp[A][B - 1][C][2]) %= mod;
                if (C > 0)
                    (dp[A][B][C][2] = dp[A][B][C - 1][0] + dp[A][B][C - 1][1]) %= mod;
            }
        }
    }   
    int ans;
    (ans = dp[a][b][c][0] + dp[a][b][c][1] + dp[a][b][c][2]) %= mod;
    cout << ans;
}