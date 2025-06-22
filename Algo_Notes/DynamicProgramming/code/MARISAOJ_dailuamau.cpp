#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
    }
    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {
            for (int k = l; k < r; k++) {
                if (s[r] == s[k])
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
            }
        }
    }
    for (int i =1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "f["<<i <<"]["<<j<<"] = " << f[i][j] << endl;
        }
    }
    cout << f[1][n];
}