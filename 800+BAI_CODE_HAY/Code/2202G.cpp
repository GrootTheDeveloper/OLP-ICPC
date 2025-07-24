#include <bits/stdc++.h>
using namespace std;


int Mlef[1001][1001][2], Mrig[1001][1001][2], Slef[1001][1001][2], Srig[1001][1001][2];
char a[1001][1001];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];

	for (int i = 1; i <= m; i++)
	for (int j = n; j >= 1; j--)
	{
		Srig[i][j][0] = Srig[i - 1][j][0] + Srig[i][j + 1][0] + (a[i][j] == 'S') - Srig[i - 1][j + 1][0];
		Srig[i][j][1] = Srig[i - 1][j][1] + Srig[i][j + 1][1] + (a[i][j] == 'S'? - i + j : 0) - Srig[i - 1][j + 1][1];

		Mrig[i][j][0] = Mrig[i - 1][j][0] + Mrig[i][j + 1][0] + (a[i][j] == 'M') - Mrig[i - 1][j + 1][0];
		Mrig[i][j][1] = Mrig[i - 1][j][1] + Mrig[i][j + 1][1] + (a[i][j] == 'M'? - i + j : 0) - Mrig[i - 1][j + 1][1];
	}
	long long ans1 = 0, ans2 = 0;

	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		Slef[i][j][0] = Slef[i - 1][j][0] + Slef[i][j - 1][0] + (a[i][j] == 'S') - Slef[i - 1][j - 1][0];
		Slef[i][j][1] = Slef[i - 1][j][1] + Slef[i][j - 1][1] + (a[i][j] == 'S'? - i - j : 0) - Slef[i - 1][j - 1][1];

		Mlef[i][j][0] = Mlef[i - 1][j][0] + Mrig[i][j - 1][0] + (a[i][j] == 'M') - Mlef[i - 1][j - 1][0];
		Mlef[i][j][1] = Mlef[i - 1][j][1] + Mrig[i][j - 1][1] + (a[i][j] == 'M'? - i - j : 0) - Mlef[i - 1][j - 1][1];


		if (a[i][j] == 'M')
		{
			ans1 += (i + j) * Mlef[i][j][0] + Mlef[i][j][1];
			ans1 += (i - j) * Mrig[i - 1][j + 1][0] + Mrig[i - 1][j + 1][1];
		}
		if (a[i][j] == 'S')
		{
			ans2 += (i + j) * Slef[i][j][0] + Slef[i][j][1];
			ans2 += (i - j) * Srig[i - 1][j + 1][0] + Srig[i - 1][j + 1][1];
		}
	}
	///cout << ans1 << ' ' << ans2;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << Slef[i][j][1] << ' ';
		cout << '\n';
	}
}