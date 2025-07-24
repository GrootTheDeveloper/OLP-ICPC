#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[111][111], a[111];
string s;
int calc(int l, int r)
{
    if (l == r) return dp[l][r] = 1;
    if (r - l == 1 && a[l] + a[r] == 0 && a[l] > 0) return dp[l][r] = 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = 1e9;
     if (a[l] + a[r] == 0 && a[l] > 0) ans = min(ans, calc(l + 1, r - 1));
    for (int k = l; k < r; k++)
        ans = min(ans, calc(l, k) + calc(k + 1, r));
    return dp[l][r] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    s = "#" + s;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '(') a[i] = 1;
        if (s[i] == ')') a[i] = -1;
        if (s[i] == '[') a[i] = 2;
        if (s[i] == ']') a[i] = -2;
    }
    cout << calc(1, s.size() - 1);
}
