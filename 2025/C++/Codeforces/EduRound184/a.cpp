#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, a; cin >> n >> a;
        vector<int> v(n + 1, 0); for (int i = 1; i <= n; i++) cin >> v[i];
        /*
        int leftSum = 0, rightSum = 0;
        int l = a - 1, r = a + 1;
        for (int i = 1; i <= n; i++) {
            if (abs(a - v[i]) > abs(l - v[i])) {
                leftSum++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (abs(a - v[i]) > abs(r - v[i])) {
                rightSum++;
            }
        }
        */
        int cntL = 0, cntR = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i] < a) cntL++;
            else if (v[i] > a) cntR++;
        }
        if (cntL > cntR) {
            cout << a - 1;
        }
        else cout << a + 1;
        cout << endl;
    }

}