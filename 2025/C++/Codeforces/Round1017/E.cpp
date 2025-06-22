#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ones(30, 0);
        for (int x : a) {
            for (int b = 0; b < 30; b++) {
                if (x & (1 << b)) {
                    ones[b]++;
                }
            }
        }
        int max_sum = 0;
        for (int x : a) {
            int s = 0;
            for (int b = 0; b < 30; b++) {
                int weight = 1 << b;
                if (x & weight) {
                    s += (n - ones[b]) * weight;
                } else {
                    s += ones[b] * weight;
                }
            }
            max_sum = max(max_sum, s);
        }
        cout << max_sum << endl;
    }
}
