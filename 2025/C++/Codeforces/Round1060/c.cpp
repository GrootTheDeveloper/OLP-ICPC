#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        int odd = 0, even = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            odd += (a[i] % 2);
        }
        even = n - odd;
        for (int i = 1; i <= n; i++) cin >> b[i];

        unordered_map<int,int> ma;
        for (int i = 1; i <= n; i++) {
            int val = a[i];
            for (int j = 1; j <= sqrt(a[i]); j++) {
                if (val % j == 0) {
                    ma[j]++;
                    if (j != (val / j)) {
                        ma[val / j]++;
                    }
                }
            }
        }
        int ans = 2;
        auto bg = ma.begin();
        int prevVal = 1;
        for (auto it = next(bg); it != ma.end(); it = next(it)) {
            if (it->first == 1) {
                continue;
            }
            if (it->second > 1) {
                ans = 0;
                break;
            }
            else {
                ans = min(ans, abs(it->first-prevVal));
                // cout << "hi " << ans << endl;
            }
            prevVal = it->first;
        }
        ans = min(ans, (odd > 0 && even > 0) ? 1 : ans);
        cout << ans << endl;
    }
}