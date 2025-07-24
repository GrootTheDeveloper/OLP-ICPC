#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k, a[100005];
bool check(int x){
    int pos = 1;
    for (int i = 1; i < k; i++){
        pos = lower_bound(a + pos + 1, a + n + 1, a[pos] + x) - a;
        if (pos == n + 1) return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e12, ans;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}
