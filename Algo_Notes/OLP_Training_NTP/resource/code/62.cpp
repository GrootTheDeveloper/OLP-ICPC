#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, d; cin >> n >> d;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    map<int,int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cnt[(f[i] % d + d) % d]++;
    }

    for (auto [val, count] : cnt) {
        ans += count * (count - 1) / 2;
    }
    cout << ans;
}