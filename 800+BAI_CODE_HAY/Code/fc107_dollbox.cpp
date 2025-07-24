#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[22], b[22];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b + 1, b + n + 1, a[i]) - b;
        a[i] = n - pos + 1;
    }
    sort(a + 1, a + n + 1);
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * (a[i] - i + 1);
    cout << ans;
}
