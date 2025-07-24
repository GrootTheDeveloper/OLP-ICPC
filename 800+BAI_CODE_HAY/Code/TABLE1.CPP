#include <bits/stdc++.h>
using namespace std;
char a[444][444];
int col[444][444];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		col[j][i] = col[j][i - 1] + (a[i][j] == 'X');
	}

	int ans = 0;
	for (int x = 1; x <= m; x++)
	for (int y = x; y <= m; y++)
	{
		int l = 0;
		for (int i = 1; i <= n; i++)
		{
			if (col[i][y] - col[i][x - 1] == 0)
				ans = max(ans, 2 * (i - l) + 2 * (y - x + 1));
			else 
				l = i;
		}
	}
	cout << ans - 1;
}