#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1;i <= n; i++) {
            cin >> a[i];
        }
        int maxN = max(n, *max_element(a.begin() + 1, a.end()));
        vector<int> cnt(maxN + 5, 0);
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        vector<int> pool;
        int count = 0;
        for (int i =  1; i <= maxN; i++) {
            if (cnt[i] == 0) {
                count++;
                pool.push_back(i);
            }
        }
        if (k <= pool.size()) {
            for (int i = 0; i < k; i++) {
                cout << pool[i] << " ";
            }
            cout << endl;
            continue;
        }

        else {
            for (int i = 0; i < k; i++) {
                cout << pool[i] << " ";
            }
            k -= pool.size();
            int i = 1;
            while (k--) {
                cout << i << " ";
                i++;
                if (i > maxN) i = 1;
            }
            cout << endl;
        }
    }
}
