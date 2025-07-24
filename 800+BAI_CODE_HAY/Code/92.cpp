#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], b[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    int l = 1, r = 1;
    a[n + 1] = b[n + 1] = 1e10;
    while (l <= n || r <= n)
    {
        if (a[l] < b[r]) cout << a[l++] << ' ';
        else cout << b[r++] << ' ';
    }
}
