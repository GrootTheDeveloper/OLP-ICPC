#include <bits/stdc++.h>
using namespace std;
#define int long long

bool hamming(int n)
{
    while (n % 2 == 0) n/=2;
    while (n % 3 == 0) n/=3;
    while (n % 5 == 0) n/=5;
    return (n == 1);
}
int a[100],b[100],c[100];
int cnt(int n)
{
    int res = 0;
    for (int i = 0; i <= 64 && a[i] <= n; i++)
        for (int j = 0; j <= 37; j++)
        if (a[i] * b[j] <= n) res += (upper_bound(c, c + 26, n / (a[i] * b[j]) )- c);
        else break;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q; cin >> q;
    a[0] = b[0] = c[0] = 1;
    for (int i = 1; i <= 64; i++) a[i] = a[i - 1] * 2;
    for (int i = 1; i <= 37; i++) b[i] = b[i - 1] * 3;
    for (int i = 1; i <= 25; i++) c[i] = c[i - 1] * 5;

    while (q--)
    {
        int m; cin >> m;
        if (!hamming(m)) cout << -1 << '\n';
        else cout << cnt(m) << '\n';
    }
}
