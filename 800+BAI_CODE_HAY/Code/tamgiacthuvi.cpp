#include <bits/stdc++.h>
using namespace std;
#define int long long 

char a[2001][2001];
int dp[2001][2001],pre[2001][4222];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("TRIANGREST.INP","r",stdin);
    freopen("TRIANGREST.OUT","w",stdout);
    int n; cin >> n;


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) 
        {
            cin >> a[i][j];
            pre[i][j] = pre[i][j-1] + (a[i][j] == '#');
        }

    int res = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n; ++i)
            if (a[l][i] == '#')
            {
                int lef = 0, rig = i;
                while (lef < rig)
                {
                    int mid = (lef + rig) / 2;
                    int k   = i - mid;
                    if (pre[l][i + k] - pre[l][mid-1] != k * 2 + 1) lef = mid + 1;
                    else rig = mid - 1;
                }
                while (a[l][lef] != '#' || pre[l][i + (i-lef)] - pre[l][lef - 1] != (i-lef)*2+1) lef ++;


                dp[l][i] = min(dp[l-1][i] + 1, i - lef + 1);
                res += dp[l][i];
            }
    }
    cout << res;

}
