#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;

    int f[n + 1];
    memset(f, 0, sizeof(f));
    // f[i] : so cach khi xet den tam van thu i
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        
        if (i - k <= 0) {
            (f[i] = f[i - 1] + 1) %= mod;
        }
        else {
            (f[i] = f[i - 1] + f[i - k] + 1) %= mod;
        }
    }
    int ans = f[n] + 1;
    ans %= mod;
    cout << ans;

}