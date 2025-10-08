#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {

    int n, s; cin >> n >> s;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    map<int,int> ma;

    ma[0] = 0;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int need = f[i] - s;
        if (ma.find(need) != ma.end()) {
            ans = max(ans, i - ma[need]);
        }
        else {
            ma[f[i]] = i;
        }
    }
    cout << ans;
}
