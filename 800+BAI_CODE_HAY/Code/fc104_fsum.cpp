#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200005], b[200005], l[200005], r[200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        b[i] = abs(a[i + 1] - a[i]);

    b[0] = b[n] = 1e9;
    for (int i = 1; i < n; i++)
    {
        int pos = i - 1;
        while (b[pos] < b[i]) pos = l[pos];
        l[i] = pos;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        int pos = i + 1;
        while (b[pos] <= b[i]) pos = r[pos];
        r[i] = pos;
    }

    long long  ans = 0;
    for (int i = 1; i < n; i++)
        ans += 1ll * b[i] * (i - l[i]) * (r[i] - i);
    cout << ans;
}
