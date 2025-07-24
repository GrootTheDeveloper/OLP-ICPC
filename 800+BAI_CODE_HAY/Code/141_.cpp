#include <bits/stdc++.h>
using namespace std;

int dp[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	int sum = 0;
	while (n--)
	{
		int w, v; cin >> w >> v;
		sum += w;
		for (int i = min(sum, s); i >= w; i--)
			dp[i] = max(dp[i], dp[i - w] + v);
	}
	cout << *max_element(dp, dp + s + 1);
}