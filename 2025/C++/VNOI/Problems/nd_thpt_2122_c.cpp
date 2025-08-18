#include <bits/stdc++.h>
#define int long long
using namespace std;

int code(string s) {
    int c = s[0];
    if (c == 'H') return 0;
    if (c == 'S') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    if (c == 'P') return 4;
    return 5;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHONDOI.INP", "r", stdin);
    freopen("CHONDOI.OUT", "w", stdout);
    int n; cin >> n;
    int cnt = 0;
    int m = 1;
    vector<int> a(6, 0);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        a[code(s)]++;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += a[i] * a[j] * a[k];
            }
        }
    }
    cout << ans;

    return 0;
}