using int64 = long long;
const int64 NEG_INF = (int64)-4e18;

int main() {
    int n, k;  if (!(cin >> n >> k)) return 0;
    vector<int64> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // dp[cur/prev][j][t], t in {0(not deleting), 1(deleting)}
    vector<array<int64,2>> dp_prev(k+1), dp_cur(k+1);
    // init: dp[0][0][0] = 0; others = -INF
    for (int j = 0; j <= k; ++j) dp_prev[j] = {NEG_INF, NEG_INF};
    dp_prev[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp_cur[j] = {NEG_INF, NEG_INF};
        for (int j = 0; j <= k; ++j) {
            // t = 0: keep A[i]
            if (dp_prev[j][0] != NEG_INF)
                dp_cur[j][0] = max(dp_cur[j][0], dp_prev[j][0] + a[i]);
            if (dp_prev[j][1] != NEG_INF)
                dp_cur[j][0] = max(dp_cur[j][0], dp_prev[j][1] + a[i]);
            // t = 1: delete at i -> A[i] contributes 0
            // continue deleting
            if (dp_prev[j][1] != NEG_INF)
                dp_cur[j][1] = max(dp_cur[j][1], dp_prev[j][1]);
            // start a new deletion segment here (use one operation)
            if (j > 0 && dp_prev[j-1][0] != NEG_INF)
                dp_cur[j][1] = max(dp_cur[j][1], dp_prev[j-1][0]);
        }
        swap(dp_prev, dp_cur);
    }

    int64 ans = NEG_INF;
    for (int j = 0; j <= k; ++j) {
        ans = max(ans, dp_prev[j][0]);
        ans = max(ans, dp_prev[j][1]);
    }
    cout << ans << '\n';
    return 0;
}