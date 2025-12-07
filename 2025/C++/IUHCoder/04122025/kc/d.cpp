#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((a[i] & a[j]) == 0) cnt++; 
        }
    }
    cout << cnt;
}