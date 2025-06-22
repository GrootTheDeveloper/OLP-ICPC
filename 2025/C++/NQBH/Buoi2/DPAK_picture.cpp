#include <bits/stdc++.h>
#define int long long

using namespace std;

// de bai: so cach de ghep N manh bang cach chon moi lan 1 -> k manh

const int MOD = 1e9 + 7;

int dq(int n, int k) {
    if (n == 0) // da du
        return 1;
    if (n < 0) return 0;

    int total = 0;
    for (int i = 1; i <= k; i++) {
        total += dq(n-i, k);
    }
    return total;
}

void dp() {
    int n, k; cin >> n >> k;
    vector<int> f(n + 1, 0);
    // f[i] : so cach ghep i manh
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(0LL,i - k); j--) {
            f[i] += f[j];
        }
    }
    cout << "QHD: " << f[n] << endl;
    cout << "DQ:  " << dq(n,k) << endl;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        dp();
    }
}