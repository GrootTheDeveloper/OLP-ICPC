#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18 + 7;

signed main() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, oo));

    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            if (p[i] > 100) {
                f[i][k + 1] = min(f[i][k + 1], f[i - 1][k] + p[i]);
                if (k > 0) {
                    f[i][k - 1] = min(f[i][k - 1], f[i - 1][k]);
                }
            }
            else {  
                f[i][k] = min(f[i - 1][k] + p[i], f[i - 1][k + 1]);
            }
        }
    }
    int ans = oo;

    for (int i = 0; i <= n; i++) {
        ans = min(ans, f[n][i]);
    }
    cout << ans;
}