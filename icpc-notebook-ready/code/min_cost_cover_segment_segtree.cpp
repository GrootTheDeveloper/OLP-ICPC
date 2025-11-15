const long long INF = (1LL<<62);
struct SegTree {
    int n;
    vector<long long> val, lz; // val: min at node, lz: pending range-chmin
    SegTree(int n=0): n(n) {
        val.assign(4*n+4, INF);
        lz.assign(4*n+4, INF);
    }
    void apply(int p, long long x) {
        val[p] = min(val[p], x);
        lz[p]  = min(lz[p],  x);
    }
    void push(int p) {
        if (lz[p] != INF) {
            apply(p<<1, lz[p]);
            apply(p<<1|1, lz[p]);
            lz[p] = INF;
        }
    }
    void range_chmin(int p, int L, int R, int i, int j, long long x) {
        if (j < L || R < i) return;
        if (i <= L && R <= j) { apply(p, x); return; }
        push(p);
        int M = (L+R)>>1;
        range_chmin(p<<1, L, M, i, j, x);
        range_chmin(p<<1|1, M+1, R, i, j, x);
        val[p] = min(val[p<<1], val[p<<1|1]);
    }
    void range_chmin(int l, int r, long long x) { if (l<=r) range_chmin(1,1,n,l,r,x); }

    long long point_query(int p, int L, int R, int idx) {
        if (L == R) return val[p];
        push(p);
        int M = (L+R)>>1;
        if (idx <= M) return point_query(p<<1, L, M, idx);
        else return point_query(p<<1|1, M+1, R, idx);
    }
    long long point_query(int idx){ return point_query(1,1,n,idx); }
};

int main() {
    int n, q; if (!(cin >> n >> q)) return 0;

    vector<vector<pair<int,long long>>> start(n+2); // start[l] -> list of (r, c)
    for (int i = 0; i < q; ++i) {
        int l, r; long long c; 
        cin >> l >> r >> c;
        if (l > r) swap(l, r);
        l = max(l, 1);
        r = min(r, n);
        if (l <= r) start[l].push_back({r, c});
    }

    vector<long long> dp(n+1, INF);
    dp[0] = 0;

    SegTree st(n); // indices 1..n, initial +INF

    for (int i = 1; i <= n; ++i) {
        // kích hoạt các gói bắt đầu tại i
        for (auto [r, c] : start[i]) {
            if (dp[i-1] < INF) {
                long long cost = dp[i-1] + c;
                st.range_chmin(i, r, cost);
            }
        }
        dp[i] = st.point_query(i);
    }

    if (dp[n] >= INF/2) cout << -1 << '\n';
    else cout << dp[n] << '\n';
    return 0;
}
