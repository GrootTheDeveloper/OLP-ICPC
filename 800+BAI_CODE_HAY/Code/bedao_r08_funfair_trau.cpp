#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x,y; cin >> x >> y;
    int l = 0, r = 0, ans = 1e18 * (-1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int mi = (int)1e12, sum = 0;
        for (int j = i; j >= 1; j--)
        {
            sum += a[j];
            mi = min(mi, a[j]);
            if (mi >= x && mi <= y && sum > ans) ans = sum, l = j, r = i;
        }
    }
    cout << ans << '\n';
    cout << l << ' ' << r;
}
