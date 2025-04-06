#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << -1;
        }
        else {
            cout << n << " ";
            for (int i = 1; i < n; i++) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
