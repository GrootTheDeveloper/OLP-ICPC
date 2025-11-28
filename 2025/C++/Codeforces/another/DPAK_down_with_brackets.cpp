#include <bits/stdc++.h>
#define int long long
using namespace std;

bool findStr(string s,  string pattern) {
    int n = s.size();
    int m = pattern.size();
    if (n < m) return false;
    for (int i = 1; i + m <= n; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != pattern[j]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        bool check = false;

        check |= (findStr(s,"(())(())"));
        check |= (findStr(s,"()()"));
        check |= (findStr(s,"(())()"));
        check |= (findStr(s,"()(())"));

        cout << (check ? "YES" : "NO") << endl;
    }
}
