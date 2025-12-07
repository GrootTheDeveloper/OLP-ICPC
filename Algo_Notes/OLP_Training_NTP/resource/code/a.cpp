#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXL = 100000;
int pow9[MAXL + 1];
int pow11[MAXL + 1];

signed main() {
    string s;
    cin >> s;
    int n = s.size();

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int k; char c;
            cin >> k >> c;
            --k;    
            s[k] = c;
        } else if (type == 2) {
            int L, R; cin >> L >> R;
            --L; --R;     
            int ans = 0;
            int i = L;
            while (i < R) {
                if (s[i] != s[i + 1]) {
                    ans++;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
