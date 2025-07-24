#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,n,k;
bool check(int x){
    int cur = 0;
    for (int i = 1; i <= m; i++){
        cur += min(x/i, n);
        if (cur >= k) return true;
    }
    return false;
}

signed main(){
    cin >> m >> n >> k;
    int l = 1, r = m * n, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}
