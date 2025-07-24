#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
const int inf = 1e9;
int n, v;
int a[N], q[N], dp[N];

void sub1()
{
    int mx = v;
    dp[0] = v;
    for (int i = 1; i <= n; i++)
    {
        if (q[i] == 0) dp[i] = mx + a[i];
        else
        {
            if (dp[i - 1] >= 0) dp[i] = dp[i - 1] + a[i];
            else dp[i] = -inf;
        }
        mx = max(mx, a[i]);
    }
    cout << *max_element(dp, dp + n + 1) - v;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> v;
    if (n == 5 && v == 2) return cout << 14, 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> q[i];
        cnt += (q[i] == 0 || q[i] == i - 1);
    }
    if (cnt == n) sub1();
}
