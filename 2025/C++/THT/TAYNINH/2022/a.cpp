#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<int,int> ma, ms;
signed main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ma[x]++;
    }
    vector<int> a; 
    for (auto [f, s] : ma) {
        a.push_back(s);
    }
    n = a.size();
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    while (i < n && a[i] == 1) {
        i++;
        ans++;
    }
    for ( ; i < n; i++) {
        int needToDelete = a[i] - 1;
        if (needToDelete > k) break;
        ans++;
        k -= needToDelete;
    }
    cout << ans;
}