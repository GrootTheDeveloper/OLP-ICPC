#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum, a[1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("dayk.inp","r",stdin);
    freopen("dayk.out","w",stdout);
	int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= k, a[i] = (a[i] + k * k) % k;
    vector<vector<int>> dp(n + 5, vector <int> (k + 5, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 0; j--)
            for (int x = 0; x < k; x++)
            {
                int mod = (x + a[i]) % k;
                if (dp[j][x] != -1) dp[i][mod] = max(dp[i][mod], dp[j][x] + 1);
            }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[i][0]);
    cout << res;

}
