#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7, MODE = mode * mode;
int dp[100005], sum[100005];
int a[100005];

int get(int l, int r)
{
	if (l > 0) return (sum[r] - sum[l - 1] + MODE) % mode;
	return sum[r];
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0] = 1;
	for (int i = 0; i <= k; i++) sum[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
			dp[j] = get(j - a[i], j) % mode;
		
		for (int x = 1; x <= k; x++)
			sum[x] = (sum[x - 1] + dp[x]) % mode;	
	}
	cout << dp[k];
}