#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int qpow(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int solve(int p, int a, int k) {
    vector<int> dp(a + 1);
    for (int i = 0; i <= a; i++) dp[i] = qpow(p, i); 
    for (int i = 1; i <= k; i++) {
        vector<int> f(a + 1);
        f[0] = dp[0];
        for (int j = 1; j <= a; j++) f[j] = (f[j - 1] + dp[j]) % MOD;

        vector<int> newdp(a + 1);
        for (int j = 0; j <= a; j++) {
            int inv = qpow(j + 1, MOD - 2);
            newdp[j] = f[j] * inv % MOD;
        }
        dp.swap(newdp);
    }
    return dp[a];
}

signed main() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> f;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int c = 0;
            while (n % p == 0) n /= p, c++;
            f.push_back({p, c});
        }
    }
    if (n > 1) f.push_back({n, 1});

    int ans = 1;
    for (auto [p, a] : f) ans = ans * solve(p,a,k) % MOD;

    cout << ans;
    return 0;
}
