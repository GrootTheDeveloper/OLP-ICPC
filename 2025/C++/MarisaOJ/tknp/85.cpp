#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;


signed main() {
    /*
    Điều kiện tam giác:
    a[i] + a[j] > a[k]
    */
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {    
            int l = j + 1, r = n;
            int ans = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (a[mid] < a[i] + a[j]) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if (ans == -1) {
                continue;
            }
            res += ans - j;
        }
    }
    cout << res;
    
}