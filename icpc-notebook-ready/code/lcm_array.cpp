// Tính LCM(a1, a2, ..., an) theo modulo 1e9+7
// LCM = ∏ p^{max_exp_p}
static const int MOD = 1'000'000'007;

long long mod_pow(long long a, long long e, long long mod = MOD) {
    long long r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}
// spf[x] = uoc nguyen to nho nhat cua x
vector<int> build_spf(int maxA) {
    vector<int> spf(maxA + 1);
    for (int i = 0; i <= maxA; ++i) spf[i] = i;
    for (int i = 2; 1LL * i * i <= maxA; ++i) {
        if (spf[i] == i) { // i is prime
            for (long long j = 1LL * i * i; j <= maxA; j += i) {
                if (spf[(int)j] == (int)j) spf[(int)j] = i;
            }
        }
    }
    return spf;
}
int main() {
    int n; cin >> n return 0;
    vector<int> a(n);
    int maxA = 0;
    for (int i = 0; i < n; ++i) 
    { cin >> a[i]; maxA = max(maxA, a[i]); }

    if (maxA <= 1) { cout << (maxA == 0 ? 0 : 1) << '\n'; return 0; }
    vector<int> spf = build_spf(maxA);
    vector<int> maxExp(maxA + 1, 0);
    for (int x : a) {
        if (x <= 1) continue;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            if (cnt > maxExp[p]) maxExp[p] = cnt;
        }
    }
    // ans = ∏ p^{maxExp[p]} (mod MOD)
    long long lcm_mod = 1;
    for (int p = 2; p <= maxA; ++p) {
        int e = maxExp[p];
        if (e > 0) {
            lcm_mod = (lcm_mod * mod_pow(p, e)) % MOD;
        }
    }
    cout << lcm_mod << '\n';
    return 0;
}
