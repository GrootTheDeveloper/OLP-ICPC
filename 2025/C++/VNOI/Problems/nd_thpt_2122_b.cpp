#include <bits/stdc++.h>
#define int long long
using namespace std;

bool compare(pair<int,int> &cur, pair<int,int> &other) {
    return cur.second > other.second;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHONBI.INP", "r", stdin);
    freopen("CHONBI.OUT", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), compare);
    int val = 0;
    for (int i = 1; i <= n; i++) {
        if (n <= a[i].first) {
            val += n * a[i].second;
            break;
        }
        val += a[i].second * a[i].first;
        n -= a[i].first;
    }
    cout << val;
    return 0;
}