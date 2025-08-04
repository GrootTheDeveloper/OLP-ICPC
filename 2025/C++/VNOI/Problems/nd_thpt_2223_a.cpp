#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    // freopen("SODEP.INP", "r", stdin);
    // freopen("SODEP.OUT", "w", stdout);
    int n; cin >> n;
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    if (res % 10 == 9) {
        cout << 1;
    }
    else cout << 0;
    return 0;
}