#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[500005];
void solve()
{
	vector <vector<int>> f(n + 3, vector<int> (n + 3, 0));
	vector <vector<int>> dp(n + 3, vector<int> (n + 3, 0));
	for (int i = 1; i <= n; i++)
	{
		f[i][i] = a[i];
		for (int j = i + 1; j <= n; j++) f[i][j] = max(f[i][j - 1], a[j]);
	}
	for (int len = 2; len < n; len++)
		for (int i = 1; i + len <= n; i++)
		{
			int x = i, y = i + len;
			dp[x][y] = max({dp[x + 1][y], dp[x][y - 1], a[x] + a[y] + f[x + 1][(x + y)/2]});
		}
	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << dp[l][r] << '\n';
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	solve();
}