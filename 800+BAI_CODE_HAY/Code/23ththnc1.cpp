#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
int col[3][1001], row[3][1001];

void solve()
{
	int m, n; cin >> m >> n;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));

	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		char x; cin >> x;
		col[x - '0'][i]++;
		row[x - '0'][j]++;
		a[i][j] = x;
	}

	long long ans = 0;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] == '1')
			ans += col[2][i] * row[2][j];
		if (a[i][j] == '2')
			ans += col[1][i] * row[1][j];
	}
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}