#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n; cin >> n;
    int sN = sqrt(n);
    int ans = 0;

    int inv2 = power(2, MOD - 2);

    for (int i = 1; i <= sN; i++) {
        (ans += (n / i) % MOD * i % MOD) %= MOD;
        int l = n / (i + 1) + 1, r = n / i;
        if (l <= sN) l = sN + 1;
        int sum = ((r % MOD * ((r+1) % MOD) % MOD * inv2 % MOD)
                        - ((l-1) % MOD * (l % MOD) % MOD * inv2 % MOD) + MOD) % MOD;
        (ans += i % MOD * sum % MOD) %= MOD;
        
    }
    cout << ans;
}
