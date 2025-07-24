#include <bits/stdc++.h>
using namespace std;
#define int long long

int b[1111];
char a[1111][1111];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        bool ans = false;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '1')
            {
                if (b[i] != j) ans = true;
            }
        }
        cout << (ans? "YES" : "NO") << '\n';
    }
}
