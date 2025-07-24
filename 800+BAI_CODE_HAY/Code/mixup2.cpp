#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[20], dp[100005][20];

bool getbit(int k, int x)
{
	return ((k >> x) & 1);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	int MASK = (1 << n);
	for (int mask = 0; mask < MASK; mask++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (getbit(mask, q - 1)) continue;
			
			for (int p = 0; p <= n; p++)
			{
				if (p != 0 && abs(a[q] - a[p]) <= k) continue;
				int newmask = mask | (1 << (q - 1));
				dp[newmask][q] += dp[mask][p];
			}
		}
	}	
	int ans = 0;
	int fullmask = (1 << n) - 1;
	for (int i = 1; i <= n; i++) ans += dp[fullmask][i];
	cout << ans;
}