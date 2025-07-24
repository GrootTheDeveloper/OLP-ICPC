#include <bits/stdc++.h>
using namespace std;
#define int long long 


int pre[1000006];
int dp[2][1000006], a[1000006];
int l[1000006];

int sum(int l, int r)
{
	return pre[r] - pre[l - 1];
}
int cnt(int l, int r)
{
	return r - l + 1;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	a[0] = 1e9 + 10;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		int pos = i - 1;
		while (a[pos] <= a[i]) pos = l[pos];
		l[i] = pos;
	}	

	int idx = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] < a[idx])
		{
			dp[0][i] = dp[0][l[i]] + cnt(l[i] + 1, i - 1) * a[i] - sum(l[i] + 1, i - 1);
			dp[1][i] = dp[0][l[i]] + cnt(l[i] + 1, i - 1) * (a[i] + 1) - sum(l[i] + 1, i - 1);
		}else
		{
			dp[0][i] = dp[0][idx] + cnt(idx + 1, i - 1) * a[idx] - sum(idx + 1, i - 1);
			dp[1][i] = dp[0][idx] + cnt(idx + 1, i - 1) * min(a[idx] + 1, a[i]) - sum(idx + 1, i - 1);
			idx = (a[i] > a[idx]? i : idx);
		}
	}


	int ans = dp[0][n];
	int chan = 0;
	for (int i = 1; i <= n; i++)
		chan = max(chan, dp[1][i] - dp[0][i]);
	cout << ans + chan;


}