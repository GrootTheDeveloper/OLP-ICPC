#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], l[100005], r[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[i] = __gcd(a[i], l[i - 1]);
    }
    for (int i = n; i >= 1; i--) r[i] = __gcd(r[i + 1], a[i]);
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, __gcd(l[i - 1], r[i + 1]));
    cout << res;
}
