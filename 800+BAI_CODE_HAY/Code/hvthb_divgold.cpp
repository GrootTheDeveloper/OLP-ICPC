#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e6;
int a[255], dp[500005], mark[500005], s, n;

void solve()
{
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = s; j >= a[i]; j--)
			if (dp[j - a[i]])
			{
				dp[j] += dp[j - a[i]];
				mark[j] = true;
				dp[j] %= mode;
			}
	int pos = 0;
	for (int i = 1; i <= s / 2; i++) if (mark[i]) pos = i;
	cout << s - 2 * pos << '\n' << dp[pos];
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("DIVGOLD.INP","r",stdin);
	freopen("DIVGOLD.OUT","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
	solve();
}