#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);

    vector<bool> prime(1e6 + 5, true);

    for (int i = 2; i * i <= 1e6; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1e6; j+=i) {
                prime[j] = false;
            }
        }
    }
    vector<int> num;
    for (int i = 2; i <= 1e6; i++) {
        if (prime[i]) num.push_back(i);
    }

    vector<int> b;
    for (int i = 0; i < num.size(); i++) {
        b.push_back(num[i] * num[i]);
    }

    int n; cin >> n;

    while (n--) {
        int x; cin >> x;

        int l = 0, r = b.size() - 1;
        int ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (b[mid] < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = b[mid];
            }
        }
        cout << ans << ' ';
    }



    return 0;
}
