#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    cin >> s;
    s = " " + s + " ";

    vector<vector<int>>f(n + 2, vector<int>(n + 2, INT_MAX));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                f[i][j] = 0;
            } 
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                f[i][j] = f[i + 1][j - 1];
            } else {
                f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            }
        }
    }

    cout << f[1][n];
}