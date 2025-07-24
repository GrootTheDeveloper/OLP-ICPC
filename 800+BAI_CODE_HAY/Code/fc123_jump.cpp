#include <bits/stdc++.h>
using namespace std;

int a[100005], nxt[100005];
int dp[100005];
signed main()
{
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	a[0] = 1e9;
	dp[0] = -1;
	nxt[n] = dp[n] = 0;

	for (int i = n - 1; i >= 1; i--)
	{
		int pos = i + 1;
		while (a[pos] <= a[i]) pos = nxt[pos];
		nxt[i] = pos;
		dp[i] = dp[pos] + 1;
	}
	while (q--)
	{
		int x; cin >> x;
		cout << dp[x] << '\n';
	}
	
}