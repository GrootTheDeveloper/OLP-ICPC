#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, x; cin >> n >> x;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    map<int,int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[f[i] - x];
        cnt[f[i]]++;
    }
    cout << ans;

}