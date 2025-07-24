#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, W;
int w[3003], a[3003], b[3003], v[3003], dp[300003];
void sub1()
{
	//memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int x = W; x >= w[i]; x--)
		for (int j = 1; j * w[i] <= x; j++)
			dp[x] = max(dp[x], dp[x - j * w[i]] + v[i] * j - a[i] * j * j + b[i]);
	}
	cout << *max_element(dp, dp + W + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i] >> b[i] >> a[i];	
	//if (n <= 100 && W <= 100) sub1();
	sub1();
}