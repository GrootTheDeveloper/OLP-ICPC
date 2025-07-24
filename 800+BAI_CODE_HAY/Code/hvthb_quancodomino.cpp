#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int up = 0, down = 0, cnt = 0;
}dp[2][1001];
int a[1001], b[1001], pra[1001], prb[1001];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("DOMINO.INP","r",stdin);
    freopen("DOMINO.OUT","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        pra[i] = pra[i - 1] + a[i];
        prb[i] = prb[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[1][i].up = 1e9; dp[1][i].down = 0;
        dp[0][i] = dp[1][i];
        for (int j = i - 1; j >= 0; j--)
        {
            int up0 = dp[0][j].up, down0 = dp[0][j].down;
            int up1 = dp[1][j].up, down1 = dp[1][j].down;
            int suma = pra[i] - pra[j], sumb = prb[i] - prb[j];
            if (abs(dp[0][i].up - dp[0][i].down) > abs((up0 + suma) - (down0 + sumb)))
            {
                dp[0][i].up = up0 + suma;
                dp[0][i].down = down0 + sumb;
                dp[0][i].cnt = dp[0][j].cnt;
            }
            if (abs(dp[0][i].up - dp[0][i].down) > abs((up1 + suma) - (down1 + sumb)))
            {
                dp[0][i].up = up1 + suma;
                dp[0][i].down = down1 + sumb;
                dp[0][i].cnt = dp[1][j].cnt;
            }
            if (abs(dp[1][i].up - dp[1][i].down) >  abs((up0 + suma - a[i] + b[i]) - (down0 + sumb - b[i] + a[i])))
            {
                dp[1][i].up = up0 + suma - a[i] + b[i];
                dp[1][i].down = down0 + sumb - b[i] + a[i];
                dp[1][i].cnt = dp[0][j].cnt + 1;
            }
            if (abs(dp[1][i].up - dp[1][i].down) >  abs((up1 + suma - a[i] + b[i]) - (down1 + sumb - b[i] + a[i])))
            {
                dp[1][i].up = up1 + suma - a[i] + b[i];
                dp[1][i].down = down1 + sumb - b[i] + a[i];
                dp[1][i].cnt = dp[1][j].cnt + 1;
            }
        }
    }
    int pos = 0;
    if (abs(dp[1][n].up - dp[1][n].down) < abs(dp[0][n].up - dp[0][n].down)) pos = 1;
    cout << abs(dp[pos][n].up - dp[pos][n].down) << ' ' << dp[pos][n].cnt;

}
