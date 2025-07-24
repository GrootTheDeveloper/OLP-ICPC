#include <bits/stdc++.h>
using namespace std;
#define int long long

char kind[500005];
int a[500005], b[500005];
int X[10], Y[10];
char type[10];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("check.inp","r",stdin);
    freopen("check.out","w",stdout);
    int n, x, y;
    while (true)
    {
        cin >> n;
        if (n == -1) return 0;
        cin >> x >> y;
        for (int i = 1; i <= n; i++)
            cin >> kind[i] >> a[i] >> b[i];
        for (int i = 1; i <= 8; i++) type[i] = 'x';
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == x)
            {
                if (b[i] > y)
                {
                    if (type[1] == 'x' || b[i] < Y[1])
                        type[1] = kind[i], Y[1] = b[i];
                }
                if (b[i] < y)
                {
                    if (type[5] == 'x' || b[i] > Y[5])
                        type[5] = kind[i], Y[5] = b[i];
                }
            }
            if (b[i] == y)
            {
                if (a[i] < x)
                {
                    if (type[7] == 'x' || a[i] > X[7])
                        type[7] = kind[i], X[7] = a[i];
                }
                if (a[i] > x)
                {
                    if (type[3] == 'x' || a[i] < X[3])
                        type[3] = kind[i], X[3] = a[i];
                }
            }

            if (abs(a[i] - x) == abs(b[i] - y))
            {
                if (a[i] < x)
                {
                    if (b[i] > y)
                    {
                        if (type[8] == 'x' || a[i] > X[8])
                            type[8] = kind[i], X[8] = a[i];
                    }
                    if (b[i] < y)
                    {
                        if (type[6] == 'x' || a[i] > X[6])
                            type[6] = kind[i], X[6] = a[i];
                    }
                }
                if (a[i] > x)
                {
                    if (b[i] > y)
                    {
                        if (type[2] == 'x' || a[i] < X[2])
                            type[2] = kind[i], X[2] = a[i];
                    }
                    if (b[i] < y)
                    {

                        if (type[4] == 'x' || a[i] < X[4])
                            type[4] = kind[i], X[4] = a[i];
                    }
                }
            }
        }
       // for (int i = 1; i <= 8; i++) cout << type[i] << ' ';
        int ans = false;
        for (int i = 1; i <= 8; i++)
        {
            if (i&1) ans = (ans || (type[i] == 'R' || type[i] == 'Q'));
            else ans = (ans || (type[i] == 'Q' || (type[i] == 'B')));
        }
        cout << (ans? "YES" : "NO") << '\n';
    }

}
