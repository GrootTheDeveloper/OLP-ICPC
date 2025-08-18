#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);
    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> div(3*1e5 + 5, 0);
    for (int i = 1; i <= 3*1e5; i++) {
        for (int j = i; j <= 3*1e5; j += i) {
            div[j] += i;
        }
    }
    for (int i = 1; i <= 3 * 1e5; i++) {
        div[i] -= i;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (div[a[i]] == a[i]) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";

    return 0;
}