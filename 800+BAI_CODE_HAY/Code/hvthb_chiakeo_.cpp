#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[55], mark[11], sum[4], ans = 1e15;


void proc()
{
    sum[1] = sum[2] = sum[3] = 0;
    for (int i = 1; i <= n; i++)
        sum[mark[i]] += a[i];
    if (sum[1] >= sum[2] && sum[2] >= sum[3]) ans = min(ans, sum[1] - sum[3]);
}
void Try(int i)
{
    if (i > n) return proc(), void();
    for (int x = 1; x <= 3; x++)
    {
        mark[i] = x;
        Try(i + 1);
    }
}
void sub1()
{
    Try(1);
    cout << ans;
}
bool dp[55555];
void sub2()
{
    int s = 0;
    for (int i = 1; i <= n; i++) s += a[i];
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = s; j >= a[i]; j--)
            if (dp[j - a[i]]) dp[j] = true;

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 10) sub1(); else sub2();
}
