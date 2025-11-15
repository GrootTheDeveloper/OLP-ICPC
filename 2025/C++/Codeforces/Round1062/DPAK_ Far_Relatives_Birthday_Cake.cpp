#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t = 1;cin >> t;
    while (t--) {
        string s; cin >> s;
        s = " " + s;
        int n = s.size() - 1;
        int ans = 0;
        int up = 0, down = 0;
        for (int i = 1; i <= n; i++) {
            bool c = (s[i] == '_');
            down += c;
            up += 1 - c;
        }
        ans = up * (down / 2) * (down / 2 + (down % 2 == 1));
        cout << ans << endl;
    }
}
