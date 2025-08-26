#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n, p, q; // p : target // q : other

bool check(vector<int> a, int numHit) {
    
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        a[i] -= numHit * q;
    }
    
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            cnt += a[i] / (p - q);
            cnt += (a[i] % (p - q) != 0);
        }
    }
    return cnt <= numHit;
}

signed main() {
    cin >> n >> p >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (p == q) {
        cout << *max_element(a.begin() + 1, a.end()) / p + (*max_element(a.begin() + 1, a.end()) % p != 0);
        return 0;
    }
    int l = 0, r = 1e9;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(a, mid)){
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;

}
