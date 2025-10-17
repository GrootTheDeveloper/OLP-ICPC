#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int BEST = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int CUR = 0;
                for (int i = l; i <= r; i++) {
                    CUR += a[i];
                }
                CUR /= (r-l + 1);
                BEST = max(BEST, CUR);
            }
        }
        cout << BEST << endl;
    }
}
