#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<vector<int>> a, vector<vector<int>> b, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1)), b(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> b[i][j];
            }
        }

        // bỏ hàng 1..r ra cuối
        // bỏ cột 1..c ra cuối
        bool ok = false;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                vector<vector<int>> temp(n + 1, vector<int>(m + 1));
                int idx = 1;
                for (int i = r + 1; i <= n; i++, idx++) temp[idx] = a[i];
                for (int i = 1; i <= r; i++, idx++) temp[idx] = a[i];

                for (int i = 1; i <= n; i++) {
                    vector<int> row(m + 1);
                    int col_idx = 1;
                    for (int j = c + 1; j <= m; j++, col_idx++) row[col_idx] = temp[i][j];
                    for (int j = 1; j <= c; j++, col_idx++) row[col_idx] = temp[i][j];
                    temp[i] = row;
                }
                if (check(temp, b, n, m)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}