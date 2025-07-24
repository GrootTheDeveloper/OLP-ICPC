#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], b[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 2; i < n; i++)
        ans = __gcd(ans, abs(a[i] - a[i - 1]));
    for (int i = 1; i <= m; i++)
    {
        int res = ans;
        res = __gcd(res, a[1] + b[i]);
        res = __gcd(res, a[n] + b[i]);
        cout << res << ' ';
    }
}
