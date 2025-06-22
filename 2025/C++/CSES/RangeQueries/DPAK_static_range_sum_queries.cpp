#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    while(q--) {
        int l, r; cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
    }
}