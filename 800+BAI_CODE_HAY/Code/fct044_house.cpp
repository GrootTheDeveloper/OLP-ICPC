#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], pre[100005], suf[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = max(pre[i - 1], a[i]);
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        suf[i] = min(suf[i + 1], a[i]);

    int ans = -1e9;
    for (int i = 1; i < n; i++)
        ans = max(ans, pre[i] - suf[i + 1]);
    if (ans < 0) cout << "Lo nang roi!";
    else cout << ans;
}
