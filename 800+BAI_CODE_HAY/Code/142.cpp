#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1001][1001];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] += max(a[i - 1][j], a[i][j - 1]);
        }
    cout << a[n][n];
}
