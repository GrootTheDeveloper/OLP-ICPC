int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> A(n+1);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    unordered_map<long long, long long> freq;
    freq.reserve(n * 2);
    freq.max_load_factor(0.7);

    for (int i = 1; i <= n; ++i) {
        long long key = A[i] ^ i; 
        ++freq[key];
    }
    long long ans = 0;
    for (auto &kv : freq) {
        long long f = kv.second;
        ans += f * (f - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
