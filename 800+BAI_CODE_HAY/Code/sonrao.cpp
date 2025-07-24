#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[250005];
const int mode = 1e9 + 7;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n + 1] = INT_MAX;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans * min({a[i - 1], a[i], a[i + 1]})) % mode;
    cout << ans;
}
