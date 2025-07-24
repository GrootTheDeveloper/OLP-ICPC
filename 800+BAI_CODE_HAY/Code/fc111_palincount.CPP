#include <bits/stdc++.h>
using namespace std;


long long c2(int n)
{
    return 1ll * n * (n - 1) / 2;
}
long long c3(int n)
{
    return 1ll * n * (n - 1) * (n - 2) / 6;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        long long ans = c3(a) * 6 + c3(b) * 6 + c2(a) * b * 2 + c2(b) * a * 2;
        cout << ans << '\n';
    }
}
