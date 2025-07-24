#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[100005], r[100005], a[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, w1, w2; cin >> n >> w1 >> w2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int left = w1 * a[1];
    for (int i = 2; i <= n; i++)
        l[i] = max(l[i - 1], w2 * a[i] + left), left = max(left, w1 * a[i]);
    int rig = w1 * a[n];
    for (int i = n - 1; i >= 1; i--)
        r[i] = max(r[i + 1], w2 * a[i] + rig), rig = max(rig, w1 * a[i]);
    int res = -1e18;
    for (int i = 3; i <= n - 2; i++) res = max(res, a[i] + l[i - 1] + r[i + 1]);
    cout << res;
}
