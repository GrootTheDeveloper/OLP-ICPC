struct SA_LCP {
    string s;
    int n;
    vector<int> sa, rnk, lcp;
    vector<int> lg2;
    vector<vector<int>> st; // RMQ min on lcp

    SA_LCP(const string& str) { build(str); }

    void build(const string& str) {
        s = str;
        n = (int)s.size();
        sa.resize(n); rnk.resize(n); lcp.resize(n);
        iota(sa.begin(), sa.end(), 0);
        for (int i = 0; i < n; ++i) rnk[i] = (unsigned char)s[i];

        vector<int> tmp(n);
        for (int k = 1;; k <<= 1) {
            auto cmp = [&](int i, int j){
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
            if (rnk[sa.back()] == n - 1) break;
        }

        // Kasai
        int h = 0;
        for (int i = 0; i < n; ++i) {
            int r = rnk[i];
            if (r == 0) { lcp[r] = 0; continue; }
            int j = sa[r - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
            lcp[r] = h;
            if (h) --h;
        }

        // RMQ on lcp[1..n-1]
        lg2.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg2[i] = lg2[i/2] + 1;
        int K = lg2[n] + 1;
        st.assign(K, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) st[0][i] = lcp[i];
        for (int k = 1; k < K; ++k) {
            int len = 1 << k;
            int half = len >> 1;
            for (int i = 0; i + len - 1 < n; ++i) {
                st[k][i] = min(st[k-1][i], st[k-1][i + half]);
            }
        }
    }

    // LCP of suffixes starting at i and j (0-based positions in s)
    int lcp_query(int i, int j) {
        if (i == j) return n - i;
        int ri = rnk[i], rj = rnk[j];
        if (ri > rj) swap(ri, rj);
        // query min lcp in (ri+1..rj) which corresponds to lcp[ri+1..rj]
        int L = ri + 1, R = rj;
        int k = lg2[R - L + 1];
        return min(st[k][L], st[k][R - (1 << k) + 1]);
    }
};

// Precompute smallest prime factor up to MAXN to factor lengths fast
struct SPF {
    int N;
    vector<int> spf;
    SPF(int n): N(n), spf(n+1) {
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; 1LL*i*i <= N; ++i)
            if (spf[i] == i)
                for (long long j = 1LL*i*i; j <= N; j += i)
                    if (spf[j] == j) spf[j] = i;
    }
    vector<int> divisors(int x) {
        vector<pair<int,int>> fac;
        while (x > 1) {
            int p = spf[x], c = 0;
            while (x % p == 0) { x /= p; ++c; }
            fac.push_back({p,c});
        }
        vector<int> divs = {1};
        for (auto [p,c] : fac) {
            int sz = (int)divs.size();
            int mul = 1;
            for (int e = 1; e <= c; ++e) {
                mul *= p;
                for (int i = 0; i < sz; ++i)
                    divs.push_back(divs[i] * mul);
            }
        }
        sort(divs.begin(), divs.end());
        return divs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: some statements include only S in first line.
    // Sample shows a length line first. We'll robustly parse:
    string first;
    if (!getline(cin, first)) return 0;
    string S;
    {
        bool all_digit = !first.empty() && all_of(first.begin(), first.end(), ::isdigit);
        if (all_digit) {
            // Next line should be S
            string lineS; getline(cin, lineS);
            S = lineS;
        } else {
            S = first;
        }
    }
    int n = (int)S.size();

    int q;
    {
        string line;
        if (!(cin >> q)) {
            // maybe there is a line with q after S in previous parsing style
            return 0;
        }
    }

    SA_LCP idx(S);

    SPF spf(max(1, n)); // for length up to n

    while (q--) {
        int l, r; cin >> l >> r;
        int L = r - l + 1;
        int ans = L;

        // enumerate divisors of L in increasing order
        auto divs = spf.divisors(L);
        for (int d : divs) {
            if (d == L) break; // last try would be L itself
            // Check if period d works: need LCP(l, l+d) >= L - d
            // convert to 0-based indices in S
            int i = l - 1;
            int j = i + d;
            if (j < n) {
                int common = idx.lcp_query(i, j);
                if (common >= L - d) { ans = d; break; }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
