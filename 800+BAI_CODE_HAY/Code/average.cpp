#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    double x = a[1];
    for (int i = 2; i <= n; i++)
        x = (x + a[i]) / 2;
    double res = 0;
    for (int i = 1; i <= n; i++)
        res += (x - a[i]);
    cout << fixed << setprecision(5) << res;
}
