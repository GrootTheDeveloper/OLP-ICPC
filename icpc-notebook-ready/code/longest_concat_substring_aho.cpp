struct Aho {
    struct Node {
        int next[26];
        int link = -1;
        vector<int> out; // lengths of patterns ending here
        Node() { memset(next, -1, sizeof(next)); }
    };
    vector<Node> tr;
    Aho() { tr.emplace_back(); }

    void add(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].next[c] == -1) {
                tr[u].next[c] = (int)tr.size();
                tr.emplace_back();
            }
            u = tr[u].next[c];
        }
        tr[u].out.push_back((int)s.size());
    }

    void build() {
        queue<int> q;
        tr[0].link = 0;
        for (int c = 0; c < 26; ++c) {
            int v = tr[0].next[c];
            if (v != -1) {
                tr[v].link = 0;
                q.push(v);
            } else {
                tr[0].next[c] = 0;
            }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int f = tr[v].link;
            // merge outputs
            if (!tr[f].out.empty()) {
                // append shorter outputs
                tr[v].out.insert(tr[v].out.end(), tr[f].out.begin(), tr[f].out.end());
            }
            for (int c = 0; c < 26; ++c) {
                int u = tr[v].next[c];
                if (u != -1) {
                    tr[u].link = tr[f].next[c];
                    q.push(u);
                } else {
                    tr[v].next[c] = tr[f].next[c];
                }
            }
        }
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    string S;
    cin >> S;
    vector<string> T(n);
    for (int i = 0; i < n; ++i) cin >> T[i];

    int N = (int)S.size();

    Aho aho;
    for (auto &t : T) {
        if (!t.empty()) aho.add(t);
    }
    aho.build();

    // Collect edges: from start i to end+1 for each match S[i..end]
    vector<vector<int>> nexts(N + 1); // edges from position i (0..N-1) to t (1..N)
    int state = 0;
    for (int i = 0; i < N; ++i) {
        int c = S[i] - 'a';
        if (c < 0 || c >= 26) { // defensive (though problem states lowercase)
            state = 0;
        } else {
            state = aho.tr[state].next[c];
        }
        if (!aho.tr[state].out.empty()) {
            for (int len : aho.tr[state].out) {
                int start = i - len + 1;
                if (start >= 0) {
                    nexts[start].push_back(i + 1); // edge start -> i+1
                }
            }
        }
    }

    // For each start l, propagate reachability along edges
    int best = 0;
    vector<char> reach(N + 1, 0);
    for (int l = 0; l < N; ++l) {
        // reset reach and propagate in one pass
        fill(reach.begin() + l, reach.end(), 0);
        reach[l] = 1;
        int farthest = l;
        for (int i = l; i <= N; ++i) {
            if (!reach[i]) continue;
            farthest = max(farthest, i);
            if (i == N) continue;
            for (int t : nexts[i]) {
                if (!reach[t]) reach[t] = 1;
            }
        }
        best = max(best, farthest - l);
        // early exit if remaining length can't beat best
        if (N - (l + 1) <= best) continue;
    }

    cout << best << '\n';
    return 0;
}
