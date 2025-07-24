#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10005], d[10004][1003];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,c; cin >> n >> c;
    int h = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], h = max(h,a[i]);
   // if (n > 1000) return 0;

    for (int i = a[1]; i <= h; i++) d[1][i] = (i - a[1]) * (i - a[1]);
    for (int i = 2; i <= n; i++)
    {
        for (int j = a[i]; j <= h; j++)
        {
            int ans = 1e15;
            for (int z = a[i - 1]; z <= h; z++)
                ans = min(ans, d[i - 1][z] + c * abs(z - j) + (j - a[i])*(j - a[i]));
            d[i][j] = ans;
        }
    }
    int res = 1e18;
    for (int i = a[n]; i <= h; i++) res = min(res, d[n][i]);
    cout << res;
}
