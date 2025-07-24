#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define a first
#define b second
int dp[7000];
ii a[3003];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, t; cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].b;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = t - 1; j >= 0; j--)
			ans = max(ans, dp[j + a[i].a] = max(dp[j + a[i].a], dp[j] + a[i].b));
	}
	cout << ans;
}