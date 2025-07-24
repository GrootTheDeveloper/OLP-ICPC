#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int x = (m * n % 2) + (k % 2);
    if (x&1) return cout << 0, 0;
    int P = (m + n) * 2;
    for (int i = 1; i <= k; i++)
    {
        int u, v, x, y; cin >> u >> v >> x >> y;
        P += 2 * (abs(u - x) + abs(v - y));
    }
    cout << P / 2 - 2 * (k + 1);
}
