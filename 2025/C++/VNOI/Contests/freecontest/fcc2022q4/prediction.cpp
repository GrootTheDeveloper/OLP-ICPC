#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int m; cin >> m;
    while (m--) {
        int u, k; cin >> u >> k;
        vector<int> a;
        for (int i = 1; i <= sqrt(u); i++) {
            if (u % i == 0) {
                a.push_back(i);
                if (i != u / i) {
                    a.push_back(u / i);
                }
            }
        } 
        sort(a.begin(), a.end());
        if (k > a.size()) {
            cout << -1 << endl;
            continue;
        }
        cout << a[k - 1] << endl;
    }
}