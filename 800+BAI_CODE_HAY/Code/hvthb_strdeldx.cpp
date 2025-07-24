#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<vector<int>> dp;

int calc(int l, int r)
{
    if (l == r) return dp[l][r] = 1;
    if (r - l == 1 && s[l] == s[r]) return dp[l][r] = 1;
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] == s[r]) return dp[l][r] = calc(l + 1, r - 1);
    int ans = 1e9;
    for (int k = l; k < r; k++)
        ans = min(ans, calc(l, k) + calc(k + 1, r));
    return dp[l][r] = ans;
}

void solve()
{
    cin >> s;
    s = "#" + s;
    int n = s.size() - 1;
    dp.assign(n + 1, vector <int> (n + 1, -1));
    cout << calc(1, n) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("strdel.inp","r",stdin);
    freopen("strdel.out","w",stdout);
    int q; cin >> q;
    while (q--) solve();
}
