#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unsafe-math-optimizations")
#pragma GCC target("avx2")
#pragma GCC target("bmi,bmi2")
#pragma GCC target("lzcnt")
#pragma GCC target("popcnt")
#pragma GCC target("fma")

#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        if (k == 1) {
            if (n == 1) {
                cout << "YES\n1\n";
            }
            else {
                cout << "NO\n";
            }
            continue;
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < n && check; ++j) {
                if (i != j) {
                    int cur = abs(a[i] - a[j]);
                    if (cur % k == 0) {
                        check = false;
                    }
                }
            }
            if (check == true) {
                ans = i + 1;
                break;
            }
        }
        if (ans == -1) cout << "NO";
        else cout << "YES" << endl << ans;
        cout << endl;
    }
}
