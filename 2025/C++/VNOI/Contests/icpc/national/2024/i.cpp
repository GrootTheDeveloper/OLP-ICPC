#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(string s) {
    if (s.size() % 2 == 1) return false;
    for (int i = 0;i < s.size()/2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}
signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= n; i++) {
            if (s[i] != t[i]) {
                string cur;
                cur += s[i];
                int j = i + 1;
                while (j <= n) {
                    cur += s[j];
                    if (check(cur)) {
                        for (int k = i; k <= j; k++) {
                            s[k] = (s[k] == '0' ? '1' : '0');
                        }
                        break;
                    }
                    j++;
                }
            }
        }
        if (s == t) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
}
