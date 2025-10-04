#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int oo = 1e18 + 7;
const int MAXN = 5e5;
using namespace std;

signed main() {
    int n, c; cin >> n >> c;
    vector<int> a(n + 1);
    vector<vector<int>> pos(MAXN + 5);

    for (int i = 1; i <= n;i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int ans = (int) pos[c].size();

    for (int i = 1; i <= MAXN; i++) {
        if (i != c) ans = max(ans, (int) pos[i].size() + (int) pos[c].size());    
    }
    cout << ans;
}