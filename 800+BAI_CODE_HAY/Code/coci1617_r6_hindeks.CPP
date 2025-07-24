#include <bits/stdc++.h>
using namespace std;
int a[500005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    if (a[i] >= i) ans = i;
    cout << ans;
}
