#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], b[100005], c[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    b[n + 1] = b[0] = c[0] = c[n + 1] = 1e15;
    int res = 1e15;
    for (int i = 1; i <= n; i++)
    {
        int pos1 = lower_bound(b + 1, b + n + 1, a[i]) - b;
        int pos2 = lower_bound(c + 1, c + n + 1, a[i]) - c;
        res = min(res, abs(a[i] - b[pos1]) + abs(b[pos1] - c[pos2]) + abs(c[pos2] - a[i]));
        res = min(res, abs(a[i] - b[pos1]) + abs(b[pos1] - c[pos2 - 1]) + abs(c[pos2 - 1] - a[i]));
        res = min(res, abs(a[i] - b[pos1 - 1]) + abs(b[pos1 - 1] - c[pos2]) + abs(c[pos2] - a[i]));
        res = min(res, abs(a[i] - b[pos1 - 1]) + abs(b[pos1 - 1] - c[pos2 - 1]) + abs(c[pos2 - 1] - a[i]));
    }
    cout << res;

}
