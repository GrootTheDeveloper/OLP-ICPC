#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
vector <vector<int>> dp;
int calc(int l, int r)
{
    if (l == r) return dp[l][r] = 0;
    if (r - l == 1 && s[l] == s[r]) return dp[l][r] = 0;
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] == s[r]) return dp[l][r] = calc(l + 1, r - 1);
    return dp[l][r] = 1 + min(calc(l, r -1), calc(l + 1, r));
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("PALIN.INP","r",stdin);
    freopen("PALIN.OUT","w",stdout);
    cin >> n;
    cin >> s;
    s = "#" + s;
    dp.assign(n + 1, vector <int> (n + 1, -1));
    cout << calc(1, n);

}
