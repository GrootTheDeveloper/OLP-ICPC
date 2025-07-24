#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1005][1005], c1[1005][1005], c2[1005][1005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            int low = min(i, n - j);
            c1[i - low][j + low]+= a[i][j];
            low = min(i, j);
            c2[i - low][j - low] += a[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int low = min(i, n - j);
            ans = max(ans, c1[i - low][j + low] + c2[i - min(i, j)][j - min(i,j)] - a[i][j]);
        }
    cout << ans;
}
