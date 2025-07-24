#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 2111992;
int dp[100005], pre[100005];
int n, k;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k + 1) dp[i] = i + 1;
        else dp[i] = (dp[i-1] + dp[i - k -1]) % mode;
    }
    cout << dp[n];

}
