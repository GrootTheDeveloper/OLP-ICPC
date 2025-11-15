const int MOD = 1'000'000'007;
const int INV2 = (int(1e9) + 8) / 2; // = 500000004

// sum_{d=l}^r d (mod MOD)
static inline long long range_sum(long long l, long long r) {
    l %= MOD; if (l < 0) l += MOD;
    r %= MOD; if (r < 0) r += MOD;
    long long cnt = (r - l + 1) % MOD; if (cnt < 0) cnt += MOD;
    long long s = (l + r) % MOD;
    return ((s * cnt) % MOD) * INV2 % MOD;
}

int main() {
    long long N;  cin >> N;

    long long ans = 0, at = 1;
    while (at <= N) {
        long long k = N / at;              // k = floor(N / d)
        long long nxt = N / k;             // d in [at, nxt] share same k

        // choose = C(k+1, 2) = k * (k + 1) / 2 mod MOD
        long long choose = ( (k % MOD) * ((k + 1) % MOD) ) % MOD;
        choose = (choose * INV2) % MOD;
        // sum d over [at..nxt]
        long long seg = range_sum(at, nxt);
        ans = (ans + seg * choose) % MOD;
        at = nxt + 1;
    }
    cout << ans << '\n';
}
