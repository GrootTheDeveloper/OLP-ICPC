#include <bits/stdc++.h>
using namespace std;
#define int long long

int d[11][200005], n, q, a[200005];
int X(int n) {return n * n;}
void sub1()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = d[i][j - 1] + (a[j] == i);
    while (q--)
    {
        int l, r; cin >> l >> r;
        int res = 0;
        for (int i = 1; i <= 10; i++)
            res += X(d[i][r] - d[i][l - 1]) * i;
        cout << res << '\n';
    }
}
int f[1000006], dp[2002][2002];
int ans;
void add(int val)
{
    ans -= X(f[val]) * val;
    ans += X(++f[val]) * val;
}
void del(int val)
{
    ans -= X(f[val]) * val;
    ans += X(--f[val]) * val;
}
void sub2()
{
    for (int len = 0; len < n; len++)
    {
        for (int i = 1; i <= len + 1; i++) add(a[i]);
        for (int i = 1; i + len <= n; i++)
        {
            if (i == 1) dp[i][i + len] = ans;
            else
            {
                del(a[i - 1]); add(a[i + len]);
                dp[i][i + len] = ans;
            }
        }
        for (int i = n - len; i <= n; i++) del(a[i]);
    }
    while (q--)
    {
        int l,r; cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    int lim = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lim = max(lim, a[i]);
    }
    if (lim <= 10) sub1();
    else if (n <= 2000) sub2();
    //sub1();
    //sub2();
}
