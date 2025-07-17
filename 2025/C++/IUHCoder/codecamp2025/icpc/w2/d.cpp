#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; cin >> n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m; cin >> m;
    vector<string> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= m; i++) {
        bool ok = false;
        for (int fi = 1; fi <= n; fi++) {
            if (a[fi] == b[i]){
                cout << 1 << endl;
                ok = true;
                break;
            }
        }
        bool ok2 = false;
        if (!ok) {
            for (int pickFirst = 1; pickFirst <= n; pickFirst++) {
                for (int pickSecond = 1; pickSecond <= n; pickSecond++) {
                    if (a[pickFirst] + a[pickSecond] == b[i]) {
                        ok2 = true;
                    }
                }
            }
            
            if (ok2) {
                cout << 2 << endl;
            } 
            else cout << 0 << endl;
        }
    }
}