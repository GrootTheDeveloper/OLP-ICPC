#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;

bool prime[2222];
int dp[111][2222];
void Sie()
{
	prime[0] = prime[1] = true;
	for (int i = 1; i * i <= 2000; i++)
	if (!prime[i]) for (int j = i * i; j <= 2000; j += i) prime[j] = true;
}
void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	Sie();
	for (int i = 0; i <= k; i++)	
		dp[1][i] = 1;
	vector<int> primes;
	for (int i = 2; i <= 2000; i++)
	if (!prime[i]) primes.push_back(i);
	for (int i = 2; i <= n; i++)
	{
		for (int x = 0; x <= k; x++)
		for (int p : primes) 
			if (p >= x) add(dp[i][x], dp[i - 1][p - x]);
	}

	int ans = 0;
	for (int i = 0; i <= k; i++)
		add(ans, dp[n][i]);
	cout << ans;

}