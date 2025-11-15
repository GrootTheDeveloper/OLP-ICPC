#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1), f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = f[i - 1] +a[i];
        }
        int maxSum = f[n];
        /*
        replace [l..r]
        bef : f[r] - f[l - 1]
        aft : (r + l) * (r - l + 1)
        -> new S = S - bef + aft
                 = S - f[r] + f[l - 1] + (r + l) * (r - l + 1)
                 = S - f[r] + f[l - 1] + r^2 -lr + r + lr -l^2 + l
                 = S - (f[r] + r^2 + r) + (f[l - 1] - l^2 + l)
        -> grow = new S - S = (f[r] + r^2 + r) - (f[l - 1] - l^2 + l)
        */
        vector<int> R(n + 1, 0), L(n + 1, 1e18);
        for (int i = 1; i <= n; i++) {
            R[i] = max(R[i - 1], f[i] + i * i + i);
        }
        for (int i = 1; i <= n; i++) {
            L[i] = min(L[i - 1], f[i - 1] - i * i + i);
        }

        for (int r = 1; r <= n; r++) {
            maxSum = max(maxSum, f[n] + R[r] - L[r]);
        }
        cout << maxSum << endl;
    }

}