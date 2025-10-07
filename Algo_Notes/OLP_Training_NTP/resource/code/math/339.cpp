#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6;
vector<int> sang(MAXN + 5, 0);
vector<int> f(MAXN + 5, 0);

void sieve() {    
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            sang[j]++;
        }
    }
    for (int i = 1; i <= MAXN; i++) {
        f[i] = f[i - 1] + sang[i];
    }
}

signed main() {
    sieve();
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int ans = f[r] - f[l - 1];
        cout << ans << endl;
    }
}
