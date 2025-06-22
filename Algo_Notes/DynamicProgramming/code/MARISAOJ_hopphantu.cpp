#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(n + 1, vector<int>(n + 1, LONG_MAX));
    // f[i][j] = chi phi it nhat khi xet doan [i..j]
    vector<int> pf(n + 1, 0);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
        pf[i] = pf[i - 1] + a[i];
    }

    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {
            for (int cut = l; cut < r; cut++) {
                f[l][r] = min(f[l][r], f[l][cut] + f[cut + 1][r] + pf[r] - pf[l - 1]);
            }
        }
    }
    cout << f[1][n];
}