#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int mul(int a, int b, int mode)
{
    int res = 0;
    while (b)
    {
        if (b&1) res = (res + a) % mode;
        a = (a + a) % mode;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, mode; cin >> n >> mode;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = mul(ans, a[i] - i + 1, mode);
    cout << ans;
}
