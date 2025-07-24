#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

int m, n, k;
int dp[1005][1005];
bool f[1005][1005];
int maxn, maxm;
int gt[200005];
void add(int &a, int b)
{
    a += b;
    if (a > mode) a -= mode;
}
void sub1()
{
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    if (!f[i][j]) add(dp[i][j], dp[i - 1][j] + dp[i][j - 1]);
    cout << dp[m][n] << '\n';
}

void init()
{
    gt[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        gt[i] = 1ll * gt[i - 1] * i % mode;
}
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1ll * res * a % mode;
        a = 1ll * a * a % mode;
        b >>= 1;
    }
    return res;
}
int C(int k, int n)
{
    return 1ll * gt[n] * power(1ll * gt[k] * gt[n - k] % mode, mode - 2) % mode;
}
void sub2()
{
    init();
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (int i = 1; i <= maxm; i++)
    for (int j = 1; j <= maxn; j++)
        if (!f[i][j]) add(dp[i][j], dp[i - 1][j] + dp[i][j - 1]);

    if (maxn == 0 && maxm == 0)
        return cout << C(n - 1, m + n - 2), void();

    int ans = 0;
    if (maxm < m)
    {
        for (int i = 1; i <= maxn; i++)
        {
            int cur = dp[maxm][i];
            int x = m - maxm - 1, y = n - i;
            add(ans, 1ll * cur * C(x, x + y) % mode);
        }
    }

    if (maxn < n)
    {
        for (int i = 1; i <= maxm; i++)
        {
            int cur = dp[i][maxn];
            int x = m - i, y = n - maxn - 1;
            add(ans, 1ll * cur * C(x, x + y) % mode);
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y; cin >> x >> y;
        maxn = max(maxn, y);
        maxm = max(maxm, x);
        f[x][y] = true;
    }
    if (m <= 1000 && n <= 1000)
        sub1();
    else sub2();
}
