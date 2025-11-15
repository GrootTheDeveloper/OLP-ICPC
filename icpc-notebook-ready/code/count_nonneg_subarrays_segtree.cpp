struct SegTree {
    int n;
    vector<long long> st;
    SegTree(int n=0): n(n), st(4*n+5, 0) {}
    void add(int p, long long v, int id, int l, int r) {
        if (l == r) { st[id] += v; return; }
        int m = (l + r) >> 1;
        if (p <= m) add(p, v, id<<1, l, m);
        else        add(p, v, id<<1|1, m+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    void add(int p, long long v){ add(p, v, 1, 1, n); }
    long long sum(int L, int R, int id, int l, int r) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return st[id];
        int m = (l + r) >> 1;
        return sum(L,R,id<<1,l,m) + sum(L,R,id<<1|1,m+1,r);
    }
    long long sum(int L, int R){ if(L>R) return 0; return sum(L,R,1,1,n); }
};

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> a(n+1,0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // prefix sums
    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + a[i];
    // coordinate compression of pref[0..n]
    vector<long long> all = pref;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    auto idx = [&](long long x){
        return int(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1; // 1-based
    };
    SegTree st((int)all.size());
    long long ans = 0;
    for (int r = 0; r <= n; ++r) {
        int id = idx(pref[r]);
        // count previous prefixes <= pref[r]
        ans += st.sum(1, id);
        // add current prefix for future
        st.add(id, 1);
    }
    cout << ans << '\n';
    return 0;
}
