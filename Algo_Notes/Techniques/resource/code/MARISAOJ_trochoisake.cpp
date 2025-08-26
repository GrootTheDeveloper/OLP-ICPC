#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    vector<bool> f(n + 1, false); 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - a[j] >= 0 && !f[i - a[j]]) {
                f[i] = !f[i - a[j]];
            }
        }
    }

    cout << (f[n] ? "Marisa" : "Reimu") << endl;
}