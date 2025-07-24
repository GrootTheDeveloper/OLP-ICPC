#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (s[i] != s[i - 1]) dp[i] = (dp[i] + dp[i - 2]) % mode;
    }
    cout << dp[n];
}
