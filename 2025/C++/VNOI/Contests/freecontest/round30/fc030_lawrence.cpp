#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> odd;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x % 2 == 1) odd.push_back(x);
            else ans += x;
        }
        sort(odd.begin(), odd.end());
        int m = odd.size();
        int l = 0, r = m - 1;

        int res = 0;
        if (ans == 0) {
            bool check = false;
            while (l <= r) {
                if (check) {
                    res += odd[r--];
                }
                else {
                    l++;
                }
                check = !check;
            }
        }
        else if (odd.empty() == false) {
            res += ans + odd[r];
            r--;
            bool check = false;
            while (l < r) {
                if (check) {
                    res += odd[r--];
                }
                else {
                    l++;
                }
                check = !check;
            }
        }
        else {
            cout << res << endl;
            continue;
        }
        cout << res << endl;

    }
    return 0;
}