int main() {
    string S, T;
    if (!getline(cin, S)) return 0;
    if (!getline(cin, T)) return 0;

    const char SEP = '#';
    // Ensure SEP not in S or T; if present, choose another (rare). For safety:
    if (S.find(SEP) != string::npos || T.find(SEP) != string::npos) {
        // find a separator not present
        for (char c = 1; c < 127; ++c) {
            if (S.find(c) == string::npos && T.find(c) == string::npos) {
                // rebuild after choosing new sep
                // We'll just set SEP via a small hack: rebuild below using string ops
                string X = T; X.push_back(c); X += S;
                int n = (int)X.size();
                vector<int> Z(n, 0);
                int l = 0, r = 0;
                for (int i = 1; i < n; ++i) {
                    if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
                    while (i + Z[i] < n && X[Z[i]] == X[i + Z[i]]) ++Z[i];
                    if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
                }
                long long ans = 0;
                int m = (int)T.size();
                for (int i = m + 1; i < n; ++i) if (Z[i] >= m) ++ans;
                cout << ans << '\n';
                return 0;
            }
        }
    }

    // Normal path with '#'
    string X;
    X.reserve(T.size() + 1 + S.size());
    X += T; X.push_back(SEP); X += S;

    int n = (int)X.size();
    vector<int> Z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && X[Z[i]] == X[i + Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }

    long long ans = 0;
    int m = (int)T.size();
    for (int i = m + 1; i < n; ++i) if (Z[i] >= m) ++ans;
    cout << ans << '\n';
    return 0;
}
