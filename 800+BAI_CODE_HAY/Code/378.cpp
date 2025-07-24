#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[222][1200];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    dp[0][0] = 1;
    int MASK = (1 << n) - 1;
    for (int i = 1; i <= m; i++)
    {
        for (int cur = 0; cur <= MASK; cur++)
        {
            if (((cur >> 1) & cur) != 0) continue;
            for (int last = 0; last <= MASK; last++)
                if (((last >> 1) & last) ==0 && (cur & last) == 0)
                    dp[i][cur] += dp[i - 1][last], dp[i][cur] %= mode;
        }
    }
    int ans = 0;
    for (int i = 0; i <= MASK; i++)
        ans += dp[m][i], ans%=mode;
    cout << ans;
}
