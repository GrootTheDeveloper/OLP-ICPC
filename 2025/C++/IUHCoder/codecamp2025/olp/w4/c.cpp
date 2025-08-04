#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; cin >> n;
    vector<int> b(n + 1);
    priority_queue<int> a;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a.push(x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    int ans = 0;
    /*
    tăng a[1]
    hoặc giảm b[i]
    */

    for (int i = 1; i <= n; i++) {
        int u = a.top();
        if (u > b[i]) continue;
        // tăng a[i]
        bool tang = false;
        int v = u + 1;
        int x = abs(v - b[i]), y = abs(u - b[i]);
        //  tang a                    giam b
        if (y < x) {
            ans += y;
        }
        else {
            while (y > x) {
                a.pop();
                a.push(v);
                v = a.top() + 1;
                x = abs(v - b[i]);
            }
            ans += x;
        }
    }
    cout << ans;
}