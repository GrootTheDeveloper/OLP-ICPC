#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int k, a, b, x, y;  cin >> k >> a >> b >> x >> y;

        int minBoth = min(a,b);
        int maxBoth = max(a, b);
        int ans = 0;

        if (k >= maxBoth) {
            // tốn x/y mỗi lần nướng
            int least = k - minBoth;
            ans += least / min(x, y) + 1;
            
        }

    }
}