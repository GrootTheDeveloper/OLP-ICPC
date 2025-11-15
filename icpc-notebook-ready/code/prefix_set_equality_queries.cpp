vector<int> buildReachSubset(const vector<int>& A, const vector<int>& B) {
    int n = (int)A.size();
    vector<int> reach(n + 1, INF); // 1..n; reach[0] = 0 (empty set is subset of empty)
    reach[0] = 0;

    unordered_set<int> inA, inB;
    inA.reserve(n * 2); inA.max_load_factor(0.7f);
    inB.reserve(n * 2); inB.max_load_factor(0.7f);

    int j = 0;            // current prefix length on B
    int need = 0;         // number of distinct elements in A[1..i] not yet in B[1..j]

    for (int i = 1; i <= n; ++i) {
        if (!inA.count(A[i-1])) {               // A[i] is new in set SA(i)
            inA.insert(A[i-1]);
            if (!inB.count(A[i-1])) ++need;     // this element not covered by B yet
        }
        while (j < n && need > 0) {
            int b = B[j++];
            if (!inB.count(b)) {
                inB.insert(b);
                if (inA.count(b)) --need;       // b fulfills one needed element
            }
        }
        if (need == 0) reach[i] = j;            // minimal j that covers SA(i)
        // else keep INF (impossible with given prefixes)
    }
    return reach;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    // Precompute minimal covering prefixes
    vector<int> reachA = buildReachSubset(A, B); // SA(i) ⊆ SB(reachA[i])
    vector<int> reachB = buildReachSubset(B, A); // SB(j) ⊆ SA(reachB[j])

    while (q--) {
        int i, j; cin >> i >> j;
        bool ok = (reachA[i] <= j) && (reachB[j] <= i);
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
