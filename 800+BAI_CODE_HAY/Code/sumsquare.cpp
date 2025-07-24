#include <bits/stdc++.h>
using namespace std;
#define int long long

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
int calc(int n, int mode)
{
    bool mask2 = false, mask3 = false;
    int a[4];
    a[1] = n, a[2] = n + 1, a[3] = 2 * n + 1;
    for (int i = 1; i <= 3; i++)
    {
        if (!mask2 && a[i] % 2 == 0) a[i] /= 2, mask2 = true;
        if (!mask3 && a[i] % 3 == 0) a[i] /= 3, mask3 = true;
    }
    return mul(a[1], mul(a[2], a[3], mode), mode);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int a = calc(2 * n + 1, m), b = calc(n, m);
    cout << (a - 4 * b % m + m) % m;
}
