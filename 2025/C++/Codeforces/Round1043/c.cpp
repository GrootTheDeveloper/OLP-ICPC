#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

signed main() {
    int t; cin >> t;
    vector<int> p3, melon;
    p3.push_back(1);
    melon.push_back(3);

    // log_3 1e9 ~~~ 19
    for (int i = 1; i <= 20; i++) {
        p3.push_back(p3.back() * 3);
        melon.push_back(pow(3, i+1) + i * pow(3, i-1));
    }

    
    while (t--) {
        int n; cin >> n;
        int cost = 0;
        while (n > 0) {
            int l = 0, r = melon.size() - 1;
            int res = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                int val = pow(3, mid);
                if (val <= n) {
                    res = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            cost += melon[res];
            n -= p3[res];
        }
        cout << cost << endl;
    }
}
