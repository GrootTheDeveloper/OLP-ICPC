#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005];

void solve()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != a[i - 1])
        {
            int pos = i;
            for (int j = a[i]; j <= a[n]; j += a[i])
            {
                pos = lower_bound(a + pos, a + n + 1, j + a[i]) - a - 1;
                res = max(res, a[pos] - j);
            }
        }
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    solve();
    //cout << '\n' << clock()/(double)1000 << " sec";
}
