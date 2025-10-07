#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2*1e6;

vector<int> left_gcd, right_gcd;

signed main() {
    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    left_gcd.resize(n + 1, a[1]);
    right_gcd.resize(n + 2, a[n]);

    for (int i = 1; i <= n; i++) {
        left_gcd[i] = gcd(left_gcd[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        right_gcd[i] = gcd(right_gcd[i + 1], a[i]);
    }

    int ans = left_gcd[n - 1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, gcd(left_gcd[i - 1], right_gcd[i + 1]));
    }

    cout << ans;
}