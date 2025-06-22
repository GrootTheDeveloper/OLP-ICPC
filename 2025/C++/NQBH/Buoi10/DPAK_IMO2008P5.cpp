#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 55;    // n tối đa (chỉnh theo đề)
const int MAXK = 105;   // k tối đa (chỉnh theo đề)

ll dp[MAXK][MAXN][MAXN];     // dp[step][on1][on2] → dùng cho N
ll dpM[MAXK][MAXN];          // dpM[step][on1] → dùng cho M

int main() {
    int n, k;
    cin >> n >> k;

    // Kiểm tra điều kiện parity trước:
    if (k < n || (k - n) % 2 != 0) {
        cout << "0 0\n";
        return 0;
    }

    // --------- Khởi tạo ---------
    memset(dp, 0, sizeof(dp));
    memset(dpM, 0, sizeof(dpM));

    dp[0][0][0] = 1;
    dpM[0][0] = 1;

    // --------- DP cho N ---------
    for (int step = 0; step < k; ++step) {
        for (int on1 = 0; on1 <= n; ++on1) {
            for (int on2 = 0; on2 <= n; ++on2) {
                ll val = dp[step][on1][on2];
                if (val == 0) continue;

                // Nhóm 1
                if (on1 < n) dp[step+1][on1+1][on2] += val * (n - on1);
                if (on1 > 0) dp[step+1][on1-1][on2] += val * on1;

                // Nhóm 2
                if (on2 < n) dp[step+1][on1][on2+1] += val * (n - on2);
                if (on2 > 0) dp[step+1][on1][on2-1] += val * on2;
            }
        }
    }

    // --------- DP cho M ---------
    for (int step = 0; step < k; ++step) {
        for (int on1 = 0; on1 <= n; ++on1) {
            ll val = dpM[step][on1];
            if (val == 0) continue;

            // Chỉ nhóm 1 vì nhóm 2 luôn tắt
            if (on1 < n) dpM[step+1][on1+1] += val * (n - on1);
            if (on1 > 0) dpM[step+1][on1-1] += val * on1;
        }
    }

    // --------- Lấy kết quả ---------
    ll N = dp[k][n][0];
    ll M = dpM[k][n];

    cout << M << " " << N << "\n";

    return 0;
}
