#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 6;
int  a[maxn], b[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int left = 0, cntl = 0, cntr = 0, rig = 0;
    for (int i = 1; i <= n; i++)
    {
        cntr += a[i];
        rig  += a[i] * b[i];
    }
    int res = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cntr -= a[i];
        rig  -= a[i] * b[i];
        res = min(res, b[i] * cntl - left + rig - b[i] * cntr);
        left += a[i] * b[i];
        cntl += a[i];
    }
    cout << res;

}
