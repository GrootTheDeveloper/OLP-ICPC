#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        s = " " + s;
        int n = s.size() - 1;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        bool allStar = true;
        for (int i = 1; i <= n; i++) {
            if (s[i] != '*') allStar = false;
        }

        if (allStar) {
            cout << -1 << endl;
            continue;
        }


        // > <
        bool check = false;
        for (int i = 1; i < n; i++) {
            if (((s[i] == '>' || s[i] == '*') && ( s[i + 1] == '<' ||  s[i + 1] == '*'))) {
                check = true;
                break;
            }
        }

        if (check) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        int sumLeft = 0, sumRight = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] != '>') sumLeft++;
            else break;
        }
        for (int i = n; i >= 1; i--) {
            if (s[i] != '<') sumRight++;
            else break;
        }
        ans = max(sumLeft, sumRight);
        if (ans == 0) ans = -1;
        cout << ans << endl;
    }

}