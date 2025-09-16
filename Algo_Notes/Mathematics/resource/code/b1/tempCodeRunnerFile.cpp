    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int MOD = 1e9 + 7;
    const int MAXN = 2e6;

    signed main() {
        int n; cin >> n;
        int sN = sqrt(n);
        int ans = 0;
        for (int i = 1; i <= sN; i++) {
            (ans += (n / i) * i) %= MOD;
            int l = n / (i+ 1) + 1, r = n / i;
            if (l <= sN) l = sN + 1;
            if (l <= r) (ans += i * (r % MOD *(r + 1) % MOD / 2 - (l - 1) % MOD *l % MOD / 2)) %= MOD;
        }
        cout << ans;
    }
