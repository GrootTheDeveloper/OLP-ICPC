#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[100005], t[100005];
int n, m;
void sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; i++) t[i] += t[i - 1];
    for (int pos = 2; pos <= m; pos++)
    {
        int k = 0;
        for (int i = 2; i <= n; i++)
        {
            if (t[i] * f[pos - 1] > t[i - 1] * f[pos])
                k = max(k, t[i] * f[pos - 1] - t[i - 1] * f[pos]);
        }
        ans += k;
        ans += (t[n] - t[n - 1]) * f[pos];
    }
    cout << ans + t[n] * f[1] << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) cin >> f[i];
    if (n <= 1000 && m <= 1000) sub1();
}
