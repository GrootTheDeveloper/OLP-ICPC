#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans = INT_MAX;
int lim, n, a[100005];

void Try(int l, int r, int res)
{
    if (l == 1 && r == lim) return ans = min(ans, res), void();
    if (l > 1)
    {
        int x = a[l - 1];
        int lef = l, rig = r;
        while (a[lef - 1] == x) lef--;
        while (a[rig + 1] == x) rig++;
        Try(lef, rig, res + 1);
    }
    if (r < lim)
    {
        int x = a[r + 1];
        int lef = l, rig = r;
        while (a[rig + 1] == x) rig++;
        Try(lef, rig, res + 1);
    }
}

void sub1()
{
    int l = n + 1;
    lim = 2 * n + 1;
    while (a[l - 1] == a[n + 1]) l--;
    Try(l, n + 1, 0);
    cout << ans;
}
const int inf = 1e9;
int dp[4022][4022];
void sub2()
{
    lim = 2 * n + 1;
    for (int i = 1; i <= lim; i++)
        fill(dp[i], dp[i] + lim + 1, inf);
    int ini = n + 1;
    while (a[ini - 1] == a[n + 1]) ini--;
    dp[ini][n + 1] = 0;
    for (int i = ini; i >= 1; i--)
    for (int j = n + 1; j <= lim; j++){
        if (i > 1)
        {
            int x = a[i - 1];
            int lef = i, rig = j;
            while (a[lef - 1] == x) lef--;
            while (a[rig + 1] == x) rig++;
            dp[lef][rig] = min(dp[lef][rig], dp[i][j] + 1);
            //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << lef << ' ' << rig << ' ' << dp[lef][rig] << '\n';
        }
        if (j < lim)
        {
            int x = a[j + 1];
            int lef = i, rig = j;
            while (a[lef - 1] == x) lef--;
            while (a[rig + 1] == x) rig++;
            dp[lef][rig] = min(dp[lef][rig], dp[i][j] + 1);
            //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << lef << ' ' << rig <<  ' ' << dp[lef][rig] << '\n';
        }
    }
    cout << dp[1][lim];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n + 1; i++)
        cin >> a[i];
    if (n <= 10) sub1();
    else sub2();

}
