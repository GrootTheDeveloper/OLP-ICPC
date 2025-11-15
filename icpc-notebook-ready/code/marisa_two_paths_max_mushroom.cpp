int main() {
    int n; if (!(cin >> n)) return 0;
    vector<vector<long long>> a(n+1, vector<long long>(n+1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    const long long NEG = -(1LL<<60);
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, NEG));
    dp[1][1] = a[1][1]; // k = 2 (i+j)

    // k = i1 + j1 = i2 + j2
    for (int k = 3; k <= 2*n; ++k) {
        vector<vector<long long>> ndp(n+1, vector<long long>(n+1, NEG));
        for (int i1 = 1; i1 <= n; ++i1) {
            int j1 = k - i1;
            if (j1 < 1 || j1 > n) continue;
            for (int i2 = 1; i2 <= n; ++i2) {
                int j2 = k - i2;
                if (j2 < 1 || j2 > n) continue;

                long long best = NEG;
                // 4 ways to come: (i1-1 or i1) x (i2-1 or i2) from previous k-1
                if (i1 > 1 && i2 > 1) best = max(best, dp[i1-1][i2-1]);
                if (i1 > 1)            best = max(best, dp[i1-1][i2]);
                if (i2 > 1)            best = max(best, dp[i1][i2-1]);
                                       best = max(best, dp[i1][i2]); // both came from right

                if (best == NEG) continue;
                long long gain = a[i1][j1] + ( (i1==i2 && j1==j2) ? 0 : a[i2][j2] );
                ndp[i1][i2] = max(ndp[i1][i2], best + gain);
            }
        }
        dp.swap(ndp);
    }

    cout << dp[n][n] << '\n';
    return 0;
}
