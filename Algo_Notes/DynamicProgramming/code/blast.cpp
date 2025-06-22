#include <bits/stdc++.h>
using namespace std;

int main() {
    string S1, S2;
    cin >> S1 >> S2;
    int m = S1.size();
    int n = S2.size();
    S1 = " " + S1;
    S2 = " " + S2;

    int k; cin >> k;

    vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i <= m; i++) {
        f[i][0] = i * k;
    }
    for (int j = 0; j <= n; j++) {
        f[0][j] = j * k;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + abs(S1[i] - S2[j]));
            f[i][j] = min(f[i][j], f[i - 1][j] + k);
            f[i][j] = min(f[i][j], f[i][j - 1] + k);
        }
    }
    cout << f[m][n];
}