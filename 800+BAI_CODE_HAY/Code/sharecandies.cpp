#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[111],dp[111][100007],pre[100005];
const int mode = 1e9 + 7;
int calc(int l, int r)
{
	if (l == 0) return pre[r];
	return (pre[r] - pre[l-1] + mode*mode) % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) dp[i][0]=1;
	for (int i = 0; i <= a[1]; ++i) dp[1][i]=1;
	int sum = a[1];

	for (int i = 2; i <= n; ++i)
	{
		sum += a[i];
		pre[0]=dp[i-1][0];
		for (int z = 1; z <= min(sum,k); z++) pre[z]=(dp[i-1][z]+pre[z-1])%mode;

		for (int j = 1; j <= min(sum,k); ++j)
				dp[i][j] = (dp[i][j] + calc(max(0ll,j-a[i]),j,sum-a[i] )) % mode;
	}

	int res=0;
	for (int i = 1; i <= n; i++) res += dp[i][k];
	cout << res % mode;
}