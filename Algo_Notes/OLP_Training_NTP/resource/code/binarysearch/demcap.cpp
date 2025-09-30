#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++) {
        int nl = l - a[i], nr = r - a[i];

        int left = i + 1, right = n;
        int ans = -1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (a[mid] >= nl && a[mid] <= nr) {
                ans = mid;
                left = mid + 1;
            } 
            else {
                
            }
        }

    }
}