#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        vector<int> x(n), y(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            x[i] = a[i].first;
            y[i] = a[i].second;
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long ans = 1LL * (x[n-1] - x[0] + 1) * (y[n-1] - y[0] + 1); // không di chuyển

        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                int x_low = x[i];
                int x_high = x[n-1-j];
                int y_low = y[i];
                int y_high = y[n-1-j];
                if (x_low > x_high || y_low > y_high) continue;
                long long area = 1LL * (x_high - x_low + 1) * (y_high - y_low + 1);
                ans = min(ans, area);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}