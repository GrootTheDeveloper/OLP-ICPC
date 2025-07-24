#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1111][1111];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 5;
    while (t--)
    {
        int m, n; cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        if (a[m][n] % 3 == 1) cout << 1;
        else if (a[m][n] % 3 == 2) cout << 0;
        else
        {
            bool ok = false;
            for (int i = 1; i <= n; i++)
                if (a[m][i] % 3 == 2 && (a[m][n] - a[m][i]) % 3 == 1) ok = true;
            for (int i = 1; i <= m; i++)
                if (a[i][n] % 3 == 2 && (a[m][n] - a[i][n]) % 3 == 1) ok = true;
            cout << ok;
        }
        cout << '\n';
    }
}
