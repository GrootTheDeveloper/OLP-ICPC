#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

signed main() {

    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int l = 0, r = 1e10;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        int lastChosen = a[1];
        int count = 1;
        for (int i = 2; i <= n; i++) {
            int dist = a[i] - lastChosen;
            if (dist >= mid) {
                count++;
                lastChosen = a[i];
            }
        }

        if (count >= k) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;

}