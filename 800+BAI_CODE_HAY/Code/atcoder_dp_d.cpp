#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, w; cin >> n >> w;
	vector <int> dp(w + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int wi, vi; cin >> wi >> vi;
		for (int i = w; i >= wi; i--)
			if (dp[i - wi] != -1)
				dp[i] = max(dp[i], dp[i - wi] + vi);
	}
	cout << *max_element(dp.begin(), dp.end());
}