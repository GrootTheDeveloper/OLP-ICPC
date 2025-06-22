#include <bits/stdc++.h>
using namespace std;

vector<int> get(int x) {
    vector<int> d;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            d.push_back(i);
            if (i != x / i) d.push_back(x / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            auto divisors = get(m - i + 1);
            for (int k : divisors) {
                if (k >= i) break; 
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            divisors.clear();
            divisors = get(n - j + 1);
            for (int k : divisors) {
                if (k >= j) break;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[m][n] << '\n';
}
