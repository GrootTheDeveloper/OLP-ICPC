#include <bits/stdc++.h>
using namespace std;
int a[200005];
int get(int l, int r)
{
    return a[r] - a[l - 1];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int sum = a[n] - a[i];
        int pos = lower_bound(a + i, a + n + 1, a[i] + sum / 2) - a;
        ans = min(ans, max({a[i], get(i + 1, pos), get(pos + 1, n)}) - min({a[i], get(i + 1, pos), get(pos + 1, n)}));
        if (pos - i > 1)
        {
            pos--;
            ans = min(ans, max({a[i], get(i + 1, pos), get(pos + 1, n)}) - min({a[i], get(i + 1, pos), get(pos + 1, n)}));
        }
    }
    cout << ans;

}
