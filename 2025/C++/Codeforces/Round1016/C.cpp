#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;
        int tempK = k - 1;
        if (n == 1) {
            while (tempK--) {
                n *= 10;
                n += 1;
            }
            if (check(n)){
                cout <<"Yes";
            }
            else cout << "No";
            cout <<endl;
            continue;
        }
        if (check(n) && k == 1) {
            cout <<"Yes";
        }
        else cout << "No";
        cout <<endl;
    }
}
