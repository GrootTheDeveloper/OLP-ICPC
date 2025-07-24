#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int d, n, a[10005], dp[10005][101];
string k;
int calc(int pos, int carry, bool lim)
{
	if (pos == 0) return (carry == 0);
	if (!lim && dp[pos][carry] != -1) return dp[pos][carry];
	int mx = (lim? a[pos] : 9);
	int ans = 0;
	for (int val = 0; val <= mx; val++)
		ans = (ans + calc(pos - 1, (carry + val) % d, (lim && val == mx))) % mode;
	if (!lim) dp[pos][carry] = ans;
	return ans;
}

int solve(string x)
{
	memset(dp, -1, sizeof(dp));
	while (!x.empty()) a[++n] = x.back() - '0', x.pop_back();
	return (calc(n, 0, true) - 1 + mode) % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> d;
	cout << solve(k);
}
