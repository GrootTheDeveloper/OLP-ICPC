#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    int n; cin >> n; vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    // hiệu số điểm lớn nhất khi người chơi gặp mảng [l..r]
    for (int i = 1; i <= n; i++) {
        f[i][i] = a[i];
    }
    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {

            f[l][r] = max(a[r] - f[l][r - 1], a[l] - f[l + 1][r]);

        }
    }   
    cout << f[1][n];
}