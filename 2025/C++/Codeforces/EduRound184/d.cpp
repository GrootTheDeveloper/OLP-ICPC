#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        if (y == 1) {
            cout << -1 << endl; continue;
        }
        int currentLength = 1000000000000;

        int ans = 0;
        for (int i = 1; i <= x; i++) {
            int blockNumber = currentLength / y + (currentLength % y != 0);
            currentLength -= blockNumber;
        }
        if (k > currentLength) {
            cout << -1 << endl;
            continue;
        }
        int blockSize = currentLength / y;
        cout << "F<3ck my self" << endl;
    }
}