#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[1001][1001];
char a[1001][1001];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int m,n; cin >> m >> n;
	string s;
	for (int i = 1; i <= m; ++i)
	{
		cin >> s;
		for (int j = 1; j <= n; ++j) a[i][j] = s[j-1];
	}
	dp[1][0]=1;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)  
			if (a[i][j] == '.') dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % mode;
	cout << dp[m][n];
}