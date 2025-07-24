#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[202], d[202], dp[202][202], lim;
string s;

int calc(int l, int r)
{
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = pow(d[l], 2);
	int ans = 0;
	if (a[l] == a[r]) ans = pow(d[l] + d[r], 2) + calc(l + 1, r - 1);
	for (int i = l; i < r; i++)	
		ans = max(ans, calc(l, i) + calc(i + 1, r));
	return dp[l][r] = ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cin >> s;
	s = "#" + s;
	int val = s[1] - '0';
	int cnt = 1;
	for (int i = 2; i <= n; i++)
	{
		if (s[i] - '0' == val) cnt++;
		else
		{
			a[++lim] = val;
			d[lim] = cnt;
			val = s[i] - '0';
			cnt = 1;
		}
	}
	a[++lim] = s[n] - '0';
	d[lim] = cnt;
	memset(dp, -1, sizeof(dp));
	cout << calc(1, lim);

}