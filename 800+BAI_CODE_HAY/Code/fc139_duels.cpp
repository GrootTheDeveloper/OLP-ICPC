#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300005], b[300005];
void solve()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++)
    {
        int p1 = lower_bound(b + 1, b + m + 1, a[i]) - b - 1;
        int p2 = upper_bound(b + 1, b + m + 1, a[i]) - b;
        A += p1;
        B += (p2 - p1 - 1);
    }
    int k1 = __gcd(A, m * n), k2 = __gcd(B, m * n);
    cout << A / k1 << '/' << m * n / k1 << '\n';
    cout << B / k2 << '/' << m * n / k2 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
}
