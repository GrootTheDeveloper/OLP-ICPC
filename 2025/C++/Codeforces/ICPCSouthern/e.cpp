#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    while (b!=0) {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

signed main() {
    int t; cin>>t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        int bad = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i + 1 <= n; i += 2) {
            if (a[i] % a[i + 1] == 0 || a[i + 1] % a[i] == 0 || gcd(a[i], a[i + 1]) == 1) {
                // hinh nhu co ai dang buon...
            }
            else bad++;
        }
        int k2 = bad + ((bad % 2) != (n % 2));
        int ans = (n + 3 * k2) / 2;
        cout << ans << endl;
    }
    return 0;
}