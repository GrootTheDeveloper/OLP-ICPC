#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 2e6;

int fact[MAXN+1], invfact[MAXN+1];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN] = power(fact[MAXN], MOD-2);
    for (int i = MAXN; i > 0; i--) invfact[i-1] = invfact[i] * i % MOD;
    int N, K; cin >> K >> N;
    cout << fact[N + K - 1] * invfact[K - 1] % MOD * invfact[N + K - 1 - (K - 1)] % MOD;
}
