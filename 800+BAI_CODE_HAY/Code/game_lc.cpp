#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k;
int d[1000006][22];

void solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int val; cin >> val;
		for (int x = 1; x <= k; x++)
		{
			d[i][x] = d[i - 1][x] + (x == val);
			if (x > val) res += d[i - 1][x];
		}
	}
	cout << res << endl;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true)
	{
		cin >> n >> k;
		if (n + k == 0) return 0;
		solve();
	}
}