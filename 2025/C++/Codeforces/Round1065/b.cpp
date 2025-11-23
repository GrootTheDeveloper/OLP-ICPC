#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i < n; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        if (a[n] != -1 && a[1] != -1) {
            cout << abs(a[n] - a[1]) << endl;
        }
        else {
            int both = max(a[n], a[1]);
            both = max(0LL, both);
            a[n] = a[1] = both;
            cout << 0 << endl;
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
