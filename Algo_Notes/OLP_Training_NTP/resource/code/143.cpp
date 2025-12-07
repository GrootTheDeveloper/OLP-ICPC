#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i<= n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    // dp[i] : dãy con tăng dài nhất kết thúc tại a[i]
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                // có thể kết hợp được a[i] với dãy con tăng dài nhất kết thúc tại a[j]
                // [1, 2, 3....., 5]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
}