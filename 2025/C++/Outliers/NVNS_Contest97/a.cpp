#include <bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
const int oo = 1e18 + 7;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << a / b * b << " " << (a + b - 1) / b * b << endl;
    }
    return 0;
}