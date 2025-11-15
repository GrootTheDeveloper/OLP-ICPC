int main() {
    string S; if (!(cin >> S)) return 0;
    int n = (int)S.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && S[i] != S[j]) j = pi[j-1];
        if (S[i] == S[j]) ++j;
        pi[i] = j;
    }
    int p = n - pi[n-1];
    if (n % p == 0) cout << S.substr(0, p) << '\n';
    else            cout << S << '\n';
    return 0;
}
