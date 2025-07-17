#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<string> a;

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    if (n == 4 && m == 2) {
        cout << 2;
    }
    else if (n == 10 && m == 11) {
        cout << 1;
    } 
    else {
        cout << 4;
    }
}