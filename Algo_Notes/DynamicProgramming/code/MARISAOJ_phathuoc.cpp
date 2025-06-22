#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {

    int n; cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    int f[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = mod;
            if (i == j) {
                f[i][i] = 0;
            }
        }
    }
    int pf[n + 1];
    memset(pf, 0, sizeof(pf));
    for (int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + a[i];
        pf[i] %= 100;
    }
    // f[l][r] : luong khoi toa ra it nhat khi xet lo [l..r]

    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {

            for (int cut = l; cut < r; cut++) {

                f[l][r] = min(f[l][r],f[l][cut] + f[cut + 1][r] + ((pf[cut] - pf[l - 1] + 100) % 100) * ((pf[r] - pf[cut] + 100) % 100)); 

            }

        }
    }
    cout << f[1][n];
}