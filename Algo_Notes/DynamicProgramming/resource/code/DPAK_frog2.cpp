#include <bits/stdc++.h>
#define int long long
const int oo = 363636363636;
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(n + 1, oo);

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1LL,i - k); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
        }
    }
    cout << dp[n];
}