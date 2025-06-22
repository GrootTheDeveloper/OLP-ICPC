#include <bits/stdc++.h>

using namespace std;
int N = 1e6;
const int NQBH = 1e3;
const int mod = 1e9 + 7;

 int dp[1005][1005];

int main(){
    for (int i = 1; i <= NQBH; i++) {
        for (int j = 1; j <= NQBH; j++) {
            dp[i][j] = 0;
        }
    }
    // dp[i][n] : số lần xuất hiện của i trong tổng xích ma n
    for (int i = 1; i <= NQBH; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i <= NQBH; i++) {
        dp[1][i] = i;
    }

    for (int i = 1; i <= NQBH; i++) {
        for (int j = 1; j <= NQBH; j++) {
            if (dp[i][j-1] == 0) continue;
            dp[i][j] = dp[i][j-1];
            if (j % i == 0) {
                dp[i][j]++;
            }
        }
    }
    cout << endl;
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][n]*i;
    }
    cout << ans;
    return 0;
}