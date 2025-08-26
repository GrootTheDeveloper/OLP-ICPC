#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    int n; cin >> n;
    vector<int> a(n + 1), pf(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    int k; cin >> k;
    unordered_map<int,int> ma;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;

            int value = pf[r] - pf[l - 1];
            if (value != 0 && k % value == 0) {
                ma[value]++;
            }
        }
    }

    int ans = 0;
    for (auto it : ma) {
        auto [val, cnt] = it;
        if (val * val == k) {
            ans += cnt * (cnt - 1) / 2;
        }
        else {
            auto jt = ma.find(k / val);
            if (jt != ma.end()) {
                ans += jt->second * cnt;
            }
        }
    }
    cout << ans;
}
