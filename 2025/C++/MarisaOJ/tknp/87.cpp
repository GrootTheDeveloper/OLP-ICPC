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

    int l = *max_element(a.begin() + 1, a.end());
    int r = 1e18;
    int ans = 1e18;
    while (l <= r) {
        int mid = l + r >> 1;
        int res = 0;
        int cnt = 0;
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            if (temp.empty()) {
                temp.push_back(a[i]);
                res += a[i];
            }
            else {
                if (res + a[i] > mid) {
                    res = a[i];
                    cnt++;
                    temp.clear();
                    temp.push_back(a[i]);
                }
                else {
                    res += a[i];
                    temp.push_back(a[i]);
                }
            }
        } 
        if (temp.empty() == false) {
            cnt++;
        }
        if (cnt <= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}