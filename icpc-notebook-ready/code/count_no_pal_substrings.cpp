
struct Solver {
    vector<int> dig; // most significant -> least
    // dp[pos][prev1][prev2][started][tight]
    // prev1, prev2 in [0..9], or 10 = NONE
    long long dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    long long dfs(int pos, int prev1, int prev2, int started, int tight) {
        if (pos == (int)dig.size()) {
            // valid number if we've started (or allow 0 as started==0 -> treat as number 0)
            return 1; // leading all zeros -> counts as 0
        }
        long long &memo = dp[pos][prev1][prev2][started][tight];
        if (vis[pos][prev1][prev2][started][tight]) return memo;
        vis[pos][prev1][prev2][started][tight] = true;
        long long res = 0;

        int up = tight ? dig[pos] : 9;
        for (int x = 0; x <= up; ++x) {
            int ntight = tight && (x == up);
            if (!started) {
                if (x == 0) {
                    // still not started: prevs remain NONE
                    res += dfs(pos + 1, 10, 10, 0, ntight);
                } else {
                    // start number with digit x: no constraints yet
                    res += dfs(pos + 1, x, 10, 1, ntight);
                }
            } else {
                // must satisfy x != prev1 and x != prev2
                if (x == prev1) continue;
                if (x == prev2) continue;
                res += dfs(pos + 1, x, prev1, 1, ntight);
            }
        }
        memo = res;
        return res;
    }

    long long count_upto(unsigned long long N) {
        dig.clear();
        if (N == 0) {
            // special: number 0 has no pal substrings (length >1), valid
            return 1;
        }
        while (N > 0) {
            dig.push_back(int(N % 10));
            N /= 10;
        }
        reverse(dig.begin(), dig.end());
        memset(vis, 0, sizeof(vis));
        return dfs(0, 10, 10, 0, 1);
    }
};

int main() {
    unsigned long long L, R;
    if (!(cin >> L >> R)) return 0;
    Solver sv;
    auto fR = sv.count_upto(R);
    auto fL = (L == 0) ? 0LL : sv.count_upto(L - 1);
    cout << (fR - fL) << '\n';
    return 0;
}
