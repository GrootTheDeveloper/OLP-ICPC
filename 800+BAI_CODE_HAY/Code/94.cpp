#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, res = 0;
    for (int r = 1; r <= n; r++)
    {
        while (a[r] - a[l] > k) l++;
        res = max(res, r - l +1);
    }
    cout << res;

}
