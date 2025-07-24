#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int a[100005], dp[100005], pre[100005], S[100005];
int sum(int l, int r)
{
	l--;
	if (l < 0) l = 0;
	return (S[r] - S[l] + mode * mode) % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, L, R; cin >> n >> L >> R;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];

	for (int i = 1; i <= n; i++)
	{
		int l = lower_bound(pre, pre + i + 1, pre[i] - R) - pre;
		int r = upper_bound(pre, pre + i + 1, pre[i] - L) - pre - 1;
		if (pre[i] >= L && pre[i] <= R) dp[i] = 1;
		dp[i] += sum(l, r);
		S[i] = (S[i - 1] + dp[i]) % mode;
	}
	cout << dp[n];

}