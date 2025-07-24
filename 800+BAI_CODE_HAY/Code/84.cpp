#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(int x){
    return x/3 + x/5 + x/7 - x/15 - x/21 - x/35 + x/105;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int l = 1, r = 1e12, ans;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (calc(mid) >= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}
