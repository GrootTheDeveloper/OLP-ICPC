#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    //freopen("AODAI.INP", "r", stdin);
    //freopen("AODAI.OUT", "w", stdout);

    int n; cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    map<int,int> ma;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 4) ans++;
        else {
            ma[a[i]]++;
        }
    }
    
    ans += ma[2] / 2;
    ma[2] = ma[2] % 2;

    if (ma[2] == 1) {
        if (ma[1] == 0) {
            ans++;
        }
        else {
            ans += min(ma[1], 1LL);
            ma[1] -= min(ma[1], 1LL);
        }
    }

    int temp =min(ma[3], ma[1]);
    ans += temp;
    ma[3] -= temp;
    ma[1] -= temp;
    if (ma[3] > 0) ans += ma[3];


    ans += ma[1] / 4 + (ma[1] % 4 != 0);
    
    cout << ans;

    return 0;
}
