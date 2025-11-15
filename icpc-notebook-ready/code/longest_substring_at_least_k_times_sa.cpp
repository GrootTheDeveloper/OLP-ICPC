static vector<int> build_sa(const string &s) {
    int n = (int)s.size();
    vector<int> sa(n), rnk(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; ++i) rnk[i] = s[i];

    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
            int ri = (i + k < n) ? rnk[i + k] : -1;
            int rj = (j + k < n) ? rnk[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        for (int i = 0; i < n; ++i) rnk[i] = tmp[i];
        if (rnk[sa.back()] == n - 1) break; // all ranks unique
    }
    return sa;
}

static vector<int> build_lcp(const string &s, const vector<int> &sa) {
    int n = (int)s.size();
    vector<int> rank(n, 0), lcp(n, 0);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    int h = 0;
    for (int i = 0; i < n; ++i) {
        int r = rank[i];
        if (r == 0) { lcp[r] = 0; continue; }
        int j = sa[r - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
        lcp[r] = h;
        if (h) --h;
    }
    return lcp; // lcp[0] = 0, lcp[i] = LCP(SA[i-1], SA[i])
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; 
    if (!(cin >> S)) return 0;
    int k; 
    if (!(cin >> k)) return 0;

    int n = (int)S.size();
    if (k <= 1) { cout << n << '\n'; return 0; }

    auto sa = build_sa(S);
    auto lcp = build_lcp(S, sa);

    // Sliding window over LCP to get min over each block of size (k-1)
    // Window r runs over LCP indices 1..n-1; for a k-suffix window ending at SA[r],
    // we need min(LCP[r-k+2..r]) length = k-1.
    deque<int> dq; // store indices of lcp with increasing values
    int best = 0;

    for (int r = 1; r <= n - 1; ++r) {
        // push lcp[r]
        while (!dq.empty() && lcp[dq.back()] >= lcp[r]) dq.pop_back();
        dq.push_back(r);

        // leftmost lcp index in current k-window
        int left = r - (k - 1) + 1; // equals r-k+2
        if (left >= 1) {
            // pop indices < left
            while (!dq.empty() && dq.front() < left) dq.pop_front();
            best = max(best, lcp[dq.front()]);
        }
    }

    cout << best << '\n';
    return 0;
}
