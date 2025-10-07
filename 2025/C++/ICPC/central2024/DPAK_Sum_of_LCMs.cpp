#include <bits/stdc++.h>
#define int long long
const int oo = 1e18 + 7;
using namespace std;

signed main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 1;
    for (int i = 401; i <= 500; i++) {
        ans = lcm(ans, i);
    }
    cout << ans;
}