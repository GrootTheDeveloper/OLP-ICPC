#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6;
vector<int> sang(MAXN + 5, 0);
signed main() {
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                sang[j]++;
                if (a[i] / j != j) {
                    sang[a[i] / j]++;
                }
            }
        }
        sang[1]++;
        sang[a[i]]++;
    }
    for (int i = 1e6; i >= 1; i--) {
        if (sang[i] > 1) {
            cout << i ;
            break;
        }
    }
}
