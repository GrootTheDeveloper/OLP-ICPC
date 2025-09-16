#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin() + 1, a.end());

        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) f[i] = f[i-1] + a[i];

        int A = 0;
        for (int i = 1; i <= n; i++) A += a[i];

        int B = 0;
        for (int i = 1; i <= n; i++) {
            B += (i - 1) * a[i] - f[i-1];
        }
        int num = A + 2 * B, den = n; 
        int g = gcd(num, den);
        num /= g;
        den /= g;
        cout << num << " " << den << endl;
    }
}
