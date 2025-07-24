#include <bits/stdc++.h>
using namespace std;
//#define long long
const int inf = 1e6;
int dp[1200000][21], beg[1200000][21];
int a[22][22];
bool check(int k, int x)
{
    return (k >> x & 1);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int MASK = (1 << n) -1;

    for (int i = 0; i <= MASK; i++)
        for (int j = 0; j <= n; j++) dp[i][j] = inf;
    for (int i = 1; i <= n; i++)
    {
        dp[(1 << (i- 1))][i] = 0;
        beg[(1 << (i- 1))][i] = i;
    }
   // cout << MASK << endl;
    for (int mask = 1; mask <= MASK; mask++)
    {
        for (int q = 1; q <= n; q++)
        {
            if (check(mask, q - 1)) continue;
            for (int p = 0; p <= n; p++)
            {
                int newmask = mask | (1 << (q - 1));
                if (dp[newmask][q] > dp[mask][p] + a[p][q])
                {
                    dp[newmask][q] = dp[mask][p] + a[p][q];
                    beg[newmask][q] = beg[mask][p];
                }
            }
        }
    }
    int ans = inf;
    int fullmask = (1 << n) - 1;
    for (int i = 1; i <= n; i++)
        if (beg[fullmask][i] != i) ans = min(ans, dp[fullmask][i] + a[i][beg[fullmask][i]]);
    cout << ans;

}