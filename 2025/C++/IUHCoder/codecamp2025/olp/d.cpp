#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {

    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    
    int l = 1, r = n;
    int ope = 0;
    while (l < r) {
        if (a[l] + a[r] <= m) {
            ope++;
            l++;
            r--;
        }
        else {
            r--;
        }
    }
    cout << n - ope;
}