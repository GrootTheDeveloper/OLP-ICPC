#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] > s[i]) return false;
    }
    return true;
}

bool dx(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ans;
        if (dx(s)) {
            cout << 0 << endl;
            continue;
        }
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
}
