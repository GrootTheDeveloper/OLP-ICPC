#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, C, D;
signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> C >> D;
        vector<int> a(n + 1), b(n+ 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int l = LLONG_MIN, r = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            int d = a[i] - b[i];
            l = max(l, d - C);
            r = min(r, d + D);
        }
        if (l > r) { cout << -1 << endl; continue; }

        int A = LLONG_MIN, B = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            A = max(A, a[i] - C);
            B = max(B, b[i] - D);
        }
        int x = A - B;
        if (x < l) x = l;
        if (x > r) x = r;

        int ch = max(B,A - x);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int ma = min(a[i] - x, b[i]);
            if (ch > ma) ans += ch - ma;
        }
        cout << ans <<  endl;
    }
}