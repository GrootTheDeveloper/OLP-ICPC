#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001][1001];
string s;
int calc(int l, int r)
{
    if (l == r) return dp[l][r] = 0;
    if (r - l == 1 && s[l] == s[r]) return dp[l][r] = 0;
    if (s[l] == s[r]) return dp[l][r] = calc(l + 1, r - 1);
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = 1 + min(calc(l + 1, r), calc(l, r - 1));
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    s = "#" + s;
    memset(dp, -1, sizeof(dp));
    cout << calc(1, s.size() - 1);

}
