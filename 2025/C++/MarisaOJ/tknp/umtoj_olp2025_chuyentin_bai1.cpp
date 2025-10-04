#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

int C(int n) {
    return n * (n - 1) / 2;
}
signed main() {

    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n - 2; i++) {
        int l = i + 1, r = n;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] - a[i] <= 2) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (res == -1) continue;
        ans += C(res - i);
    }
    cout << ans;
}