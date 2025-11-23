#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 != 0 && n % 4 != 0) {
            cout << 0 << endl;
        }
        else {
            int num = 0;
            for (int chick = 0; chick <= n; chick++) {
                for (int cow = 0; cow <= n; cow++) {
                    int temp = chick * 2 + cow * 4;
                    if (temp == n) num++;
                }
            }
            cout << num << endl;
        }
    }
}
