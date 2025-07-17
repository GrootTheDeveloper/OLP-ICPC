#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int nam, nu, thuctap;
    cin >> nam >> nu >> thuctap;
    while (thuctap > 0) {
        int temp_nam = nam - 1;
        int temp_nu = nu - 1;
        int minus_nam = min(temp_nam / 2, nu);
        int minus_nu = min(nam / 2, temp_nu);
        if (minus_nam > minus_nu) {
            nam = temp_nam;
        }
        else nu = temp_nu;
        thuctap--;
    }
    int ans = min(nam / 2, nu);
    cout << ans;
}