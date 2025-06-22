#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<vector<int>>f(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    f[1][0] = a[1];
    f[1][1] = b[1];
    f[1][2] = c[1];

    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i-1][1], f[i - 1][2]) + a[i];
        f[i][1] = max(f[i-1][0], f[i - 1][2]) + b[i];
        f[i][2] = max(f[i-1][0], f[i - 1][1]) + c[i];
    }

    int ans = max({f[n][0], f[n][1], f[n][2]});
    cout << ans;
}