const int MAX_SUM = 9 * 19; // 171
// Sieve primes up to 171
vector<int> isPrimeVec() {
    int N = MAX_SUM;
    vector<int> prime(N+1, 1);
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= N; ++p)
        if (prime[p])
            for (int q = p*p; q <= N; q += p) prime[q] = 0;
    return prime;
}

struct DigitDP {
    vector<int> prime;
    // memo[pos][sum][tight?] is too big if 3D; we compress tight by separate calls
    long long memo[20][MAX_SUM+1];
    bool vis[20][MAX_SUM+1];
    vector<int> digs;

    DigitDP(): prime(isPrimeVec()) {}

    long long dfs(int pos, int sum, bool tight) {
        if (pos == (int)digs.size())
            return prime[sum]; // full number formed: count if sum is prime

        if (!tight && vis[pos][sum]) return memo[pos][sum];

        int limit = tight ? digs[pos] : 9;
        long long res = 0;
        for (int d = 0; d <= limit; ++d) {
            res += dfs(pos+1, sum + d, tight && (d == limit));
        }

        if (!tight) {
            vis[pos][sum] = true;
            memo[pos][sum] = res;
        }
        return res;
    }

    // count numbers in [0..x] whose digit-sum is prime
    long long count_upto(unsigned long long x) {
        digs.clear();
        if (x == 0) { // only 0
            return 0; // 0 is not counted (sequence starts from positive integers)
        }
        // build digits (most significant first)
        vector<int> tmp;
        while (x > 0) { tmp.push_back(int(x % 10)); x /= 10; }
        reverse(tmp.begin(), tmp.end());
        digs = move(tmp);
        // clear memo
        memset(vis, 0, sizeof(vis));
        return dfs(0, 0, true) - 0 /* exclude 0 explicitly */;
    }
};

int main() {
    unsigned long long k;
    if (!(cin >> k)) return 0;

    if (k == 0) { 
        cout << 0 << '\n';
        return 0;
    }
    DigitDP dp;
    // exponential search to find high bound with count >= k
    unsigned long long lo = 1, hi = 1;
    while (dp.count_upto(hi) < (long long)k) {
        if (hi > (unsigned long long)4e18) break;
        hi <<= 1;
    }
    // binary search
    while (lo < hi) {
        unsigned long long mid = lo + ((hi - lo) >> 1);
        if (dp.count_upto(mid) >= (long long)k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}
