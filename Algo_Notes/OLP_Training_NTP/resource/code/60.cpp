#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    vector<int> minF(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        minF[i] = min(minF[i - 1], f[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] - minF[i]);
    }
    cout << ans << endl;
}