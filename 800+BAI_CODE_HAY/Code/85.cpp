#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1555];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int pos = lower_bound(a + j, a + n + 1, a[i] + a[j]) - a;
            res += pos - j - 1;
        }
    cout << res;
}
