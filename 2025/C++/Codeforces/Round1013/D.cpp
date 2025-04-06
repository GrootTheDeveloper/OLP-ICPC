#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int free = n * m - k;
        int divSit = free / n;
        int ans = m / (divSit + 1);
        cout << ans << endl;
    }
    return 0;
}