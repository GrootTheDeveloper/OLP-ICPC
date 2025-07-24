#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int a[10005], d[111][111];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> d[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    int res = 0;
    for (int i = 1; i < m; i++) res += d[a[i]][a[i+1]];
    cout << res;
}
