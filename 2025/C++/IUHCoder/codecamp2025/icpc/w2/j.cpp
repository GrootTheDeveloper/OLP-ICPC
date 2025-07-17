    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define endl "\n"

    signed main() {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n <= 2) {
            cout << 0;
            return 0;
        }
        vector<int> fuck;
        fuck.push_back(a[2] - a[1]);
        fuck.push_back(a[3] - a[2]);
        if ((a[3] - a[1]) % 2 == 0) fuck.push_back((a[3] - a[1]) / 2);

        int exPos = 1e18, exVal;
        for (auto d : fuck) {
            int errorCount = 0;
            int errorPos = -1;
            int newVal = -1;

            bool ok = true;
            for (int i = 3; i <= n; i++) {
                if (a[i] - a[i-1] != d) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                exPos = min(exPos, 1LL);
                exVal = a[2] - d;
            }

            for (int i = 1; i <= n; i++) {
                int expected = a[1] + (i - 1) * d;
                if (a[i] != expected) {
                    errorCount++;
                    errorPos = i;
                    newVal = expected;
                }
                if (errorCount > 1) break;
            }

            if (errorCount == 1) {
                if (exPos > errorPos) {
                    exPos = errorPos;
                    exVal = newVal;
                }
            }
        
            if (errorCount == 0) {
                if (ok) {
                    cout << exPos << " " << exVal;
                }
                else cout << 0;
                return 0;
            }
        }
        if (exPos != 1e18) {
            cout << exPos << " " << exVal;
            return 0;
        }
        cout << -1;
    }