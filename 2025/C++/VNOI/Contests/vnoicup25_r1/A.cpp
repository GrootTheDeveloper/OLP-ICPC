#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = 300005;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        if (s.size() < 3) {
            cout << "No" << endl;
            continue;
        }
        bool check = false;
        int l = -1, r = -1;
        for (int i = 0; i < s.size() - 2; i++) {
            int cntU = 0, cntI = 0;
            for (int j = i; j <= i + 2; j++) {
                if (s[j] == 'U') {
                    cntU++;
                }
                else {
                    cntI++;
                }
            }
            if (cntU == 2 && cntI == 1 || cntU == 1 && cntI == 2) {
                l = i + 1, r = i + 2 + 1;
                check = true;
                break;
            } 
        }
        if (check) {
            cout << "Yes" << " " << l << " " << r << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}