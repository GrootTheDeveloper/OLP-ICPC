#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[202][5005];
int b[5005][202];
int a[5005], pos[5005];
int n, m;

void sub1()
{
	
	pos[1] = 0;
	for (int i = 2 ; i <= n; i++)
		pos[i] = pos[i - 1] + a[i - 1];

	for (int i = 1; i <= m; i++)
		fill(dp[i], dp[i] + n + 1, -1e15);
	for (int i = 1; i <= n; i++)
		dp[1][i] = b[i][1];

	for (int i = 2; i <= m; i++)
	for (int j = 1; j <= n; j++)
	for (int z = 1; z <= n; z++)
		dp[i][j] = max(dp[i][j], dp[i - 1][z] + b[j][i] - abs(pos[z] - pos[j]));
	

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}

	//cout << *max_element(dp[m] + 1, dp[m] + n + 1); 

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> b[i][j];
	sub1();
}