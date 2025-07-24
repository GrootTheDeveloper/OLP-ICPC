#include <bits/stdc++.h>
using namespace std;
#define int long long

int up(int n) {return n*2 - 1;}
int close(int n) {return n*2;}
int a[5555][20];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n; cin >> m >> n;
    for (int i = 1; i <= m * 2; i++)
        for (int j = 1; j <= n - 1 + (i&1); j ++) cin >> a[i][j];
    vector <vector<int>> dp(m + 2, vector <int> (n + 2, 10000000000));
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j ++)
        {
            dp[i][j] = dp[i-1][j] + a[up(i)][j];
            int cost = 0;
            for (int z = j - 1; z >= 1; z--)
            {
                cost += a[close(i)][z];
                dp[i][j] = min(dp[i][j],dp[i-1][z] + cost + a[up(i)][z]);
            }
            cost = 0;
            for (int z = j; z <= n; z++)
            {
                cost += a[close(i)][z];
                dp[i][j] = min(dp[i][j], dp[i-1][z+1] + cost + a[up(i)][z+1]);
            }
        }
    cout << dp[m][n];


}
