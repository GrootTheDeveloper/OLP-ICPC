#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    vector<vector<int>> f(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i <= min(a,b); i++) {
        f[i][i] = 0;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) continue;
            for (int k = 1; k <= i - 1; k++) {
                f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
            }
            for (int k = 1; k <= j - 1; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
            }
        }
    }
    cout << f[a][b];
}