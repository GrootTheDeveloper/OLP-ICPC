#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, q; cin >> n >> q;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(1e5 + 1);
    
    // pos[i] : là tập hợp các vị trí mà phần tử tại vị trí đó có giá trị là i

    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        int minLeft = 0, minRight = pos[x].size() - 1;
        int minRes = -1;
        while (minLeft <= minRight) {
            int mid = minLeft + minRight >> 1;
            if (pos[x][mid] < l) {
                minLeft = mid + 1;
            }
            else {
                minRes = mid;
                minRight = mid - 1;
            }
        }
        int maxLeft = 0, maxRight = pos[x].size() - 1;
        int maxRes = pos[x].size() + 5;
        while (maxLeft <= maxRight) {
            int mid = maxLeft + maxRight >> 1;
            if (pos[x][mid] > r) {
                maxRight = mid - 1;
            }
            else {
                maxRes = mid;
                maxLeft = mid + 1;
            }
        }
        int ans = 0;
        if (minRes != -1 && maxRes != pos[x].size() + 5 && pos[x][minRes] >= l && pos[x][maxRes] <= r) {
            ans = maxRes-minRes + 1;
        }
        cout << ans << endl;
    }
}