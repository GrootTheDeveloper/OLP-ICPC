#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n; 

bool check(vector<pair<int,int>> &a, int limit) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur -= a[i].first;
        cur += a[i].second;
        if (cur > limit) return false;
    }
    return cur <= limit;
}
signed main() {

    cin >> n;
    vector<pair<int,int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int l = 0, r = 1e18;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(a, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;

}