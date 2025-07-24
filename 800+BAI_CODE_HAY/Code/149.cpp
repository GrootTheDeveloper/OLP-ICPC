#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[5555], b[5555];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int res = -1e18;
    for (int len = 0; len < n; len++)
    {
        int ans1 = 0, ans2 = 0,  sum1 = 0, sum2 = 0;
        for (int i = 1; i + len <= n; i++)
        {
            sum1 += a[i] * b[i + len];
            sum2 += b[i] * a[i + len];
            res = max({res, sum1 - ans1, sum2 - ans2});
            ans1 = min(ans1, sum1);
            ans2 = min(ans2, sum2);
        }
    }
    cout << res;
}
