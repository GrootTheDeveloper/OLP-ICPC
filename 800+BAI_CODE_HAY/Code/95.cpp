#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005], a[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, res = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] - a[l] > x) l++;
        res = max(res, i - l + 1 + dp[l - 1]);
        dp[i] = max(dp[i - 1], i - l + 1);
    }
    cout << res;

}
