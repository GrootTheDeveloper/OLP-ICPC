#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, k; cin >> n >> k;

    vector<int>a(n + 1);
    vector<int>f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        int idx = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            int total = f[i] - f[mid - 1];
            if (total >= k) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ans += idx;
    }
    cout << ans;
}