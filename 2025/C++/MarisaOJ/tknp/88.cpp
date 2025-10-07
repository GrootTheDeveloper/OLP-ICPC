#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

signed main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << i * j << '\t';
        }
        cout << endl;
    }
}