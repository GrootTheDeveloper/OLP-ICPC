#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    int n; cin >> n;
    vector<int>a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    int ans = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = a[i] * b[j] + max(0LL, f[i - 1][j - 1]);
            ans = max(ans, f[i][j]);
        }
    }


    cout << ans;
    bgfv
}