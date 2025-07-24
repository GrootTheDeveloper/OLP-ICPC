#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second 
int dp[3003][3003];
pair<int,int> par[3003][3003];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	int m = s.size(), n = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + 1, par[i][j] = {i,j};
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (dp[i][j - 1] > dp[i - 1][j])
					par[i][j] = par[i][j - 1];
				else
					par[i][j] = par[i - 1][j];
			}
	int LIS = dp[m][n];
	int x = m, y = n;
	vector <char> ans;
	while (LIS)
	{
		int nx = par[x][y].x, ny = par[x][y].y;
		if (x == nx && y == ny)
		{
			LIS--;
			ans.push_back(s[x]);
			x--;
			y--;
		}else
		{
			x = nx;
			y = ny;
		}
	}
	reverse(begin(ans), end(ans));
	for (char c : ans) cout << c;
}