#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (a == b) cout << 0 << endl;
        else {
            int lcm = a / gcd(a,b) * b;
            int ans = (a != lcm) + (b != lcm);
            cout << ans << endl;
        }
    }
}