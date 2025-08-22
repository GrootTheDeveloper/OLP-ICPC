#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >>n;
        int K = 1;
        vector<int>ans;
        for (int k = 1; k <= 18; k++) {
            int m = 1 + (K *= 10);
            if (n % m == 0) {
                ans.push_back(n/m);
            }
        }
        if (ans.empty()) cout << 0;
        else {
            cout << ans.size() << endl;
            sort(ans.begin(), ans.end());
            for (auto num : ans) {
                cout << num << " ";
            }
        }
        cout << endl;
    }
}
