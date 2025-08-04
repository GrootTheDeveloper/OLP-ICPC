#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    freopen("THUGON.INP", "r", stdin);
    freopen("THUGON.OUT", "w", stdout);
    string s; 
    while (cin >> s) {
        char first = s[0];
        int n = s.size();
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != first) {
                if (cnt > 1) cout << cnt; 
                cout << first ;
                cnt = 1;
                first = s[i];
            }
            else {
                cnt++;
            }
        }
        if (cnt > 1) cout << cnt; 
        cout << first << endl;
    }
    return 0;
}
