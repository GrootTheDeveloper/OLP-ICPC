#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;

    vector<vector<bool>> f(n + 1, vector<bool>(n + 1));

    for (int i = 1; i <= n; i++) {
        f[i][i] = true;
    }

    for (int r = 1; r <= n; r++) {
        for (int l = 1; l < r; l++) {
            if (s[r] == s[l]) {
                if (r == l + 1) {
                    f[l][r] = true;
                }
                else
                    f[l][r] = f[l + 1][r - 1];
            }
            else {
                f[l][r] = false;
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (f[l][r] ? "YES" : "NO") << endl;
    }
}