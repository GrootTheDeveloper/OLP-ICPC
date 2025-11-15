struct BitDP {
    // Preloaded bit arrays for N (upper bound on y) and S (upper bound on x^y)
    int NB[64], SB[64], XB[64];
    long long dp[64][2][2];
    bool vis[64][2][2];

    long long dfs(int i, int ty, int tz) {
        if (i < 0) return 1; // all bits assigned
        if (vis[i][ty][tz]) return dp[i][ty][tz];
        vis[i][ty][tz] = true;
        long long res = 0;

        int nbi = NB[i], sbi = SB[i], xbi = XB[i];
        for (int yi = 0; yi <= 1; ++yi) {
            if (ty && yi > nbi) continue;                 // exceed N at this bit
            int zi = yi ^ xbi;
            if (tz && zi > sbi) continue;                 // exceed S at this bit
            int nty = ty && (yi == nbi);
            int ntz = tz && (zi == sbi);
            res += dfs(i - 1, nty, ntz);
        }
        return dp[i][ty][tz] = res;
    }

    long long count_upto(unsigned long long x, unsigned long long N, unsigned long long S) {
        // fill bit arrays (LSB at index 0)
        for (int i = 0; i < 64; ++i) {
            NB[i] = (N >> i) & 1ULL;
            SB[i] = (S >> i) & 1ULL;
            XB[i] = (x >> i) & 1ULL;
        }
        memset(vis, 0, sizeof(vis));
        return dfs(63, 1, 1);
    }
};

int main() {
    unsigned long long x, L, R, S;
    if (!(cin >> x >> L >> R >> S)) return 0;

    BitDP solver;
    auto FR = solver.count_upto(x, R, S);
    auto FL = (L == 0 ? 0LL : solver.count_upto(x, L - 1, S));
    cout << (FR - FL) << '\n';
    return 0;
}
