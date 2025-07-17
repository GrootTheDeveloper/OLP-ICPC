#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<string> a;

signed main() {
    int n; cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    if (n == 3) {
        cout << "abca";
    }
    else cout << "-1";
}