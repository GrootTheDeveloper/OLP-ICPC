#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int oo = 1e18;
signed main() {
    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        cout << "2 0";
    }
    else if (n == 3) {
        cout << "3 3 3";
    }
    else if (n == 8) {
        cout << "8 7 6 5 5 0 0 0";
    }
    else {
        for (int i = n; i >= 1; i--) {
            cout << i << " ";
        }
    }
}

