#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n,k;
bool Divk(int x){
    int pos = 0;
    for (int i = 1; i <= k; i++){
        int newpos = upper_bound(a + pos + 1, a + n + 1, a[pos] + x) - a - 1;
        if (newpos == pos) return false;
        pos = newpos;
        if (pos == n) return true;
    }
    return pos == n;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    int l = 1, r = 1e15, ans;
    while (l <= r){
        int mid = (l + r) / 2;
        if (Divk(mid)) ans = mid, r = mid -1;
        else l = mid + 1;
    }
    cout << ans;

}
