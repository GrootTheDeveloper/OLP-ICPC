#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; 
    while (cin >> n) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n <= 2) {
            cout << 1;
            continue;
        }
        int ans = n - 1;
        for (int i = n - 1; i >= 2; i--) {
            if (a[i] - a[i - 1] == a[n] - a[n - 1]) {
                ans = i - 1;
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
}