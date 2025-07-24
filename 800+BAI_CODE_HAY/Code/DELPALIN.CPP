#include <bits/stdc++.h>
using namespace std;
int dp[333][333];

string s;
int solve(int l, int r)
{
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r || (r - l == 1 && s[r] == s[l])) return dp[l][r] = 1;
	int ans = 1e9;
	if (s[l] == s[r]) ans = solve(l + 1, r - 1);
	for (int i = l; i < r; i++)
		ans = min(ans, solve(l, i) + solve(i + 1, r));
	return dp[l][r] = ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t; 
	while (t--)
	{
		cin >> s;
		memset(dp, -1, sizeof(dp));
		cout << solve(0, (int)s.size() - 1) << '\n';
	}
}