#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[100005], b[100005], dp[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("BAI05.INP","r",stdin);
	freopen("BAI05.OUT","w",stdout);
	int n, m, p, T, B; cin >> n >> m >> p >> T >> B;
	p += 2;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 2; i <= p - 1; i++) cin >> b[i];
	b[1] = 1; b[p] = n;
	sort(a + 1, a + m + 1);

	for (int i = 2; i <= p; i++)
	{
		int val = a[upper_bound(a + 1, a + m + 1, b[i]) - a - 1];
		int pos = lower_bound(b + 1, b + p + 1, val) - b;
		dp[i] = dp[i - 1] + T * (b[i] - b[i - 1]);
		dp[i] = min(dp[i], dp[pos] + B);
	}
	cout << dp[p];
}