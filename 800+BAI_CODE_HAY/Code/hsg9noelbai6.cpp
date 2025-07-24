#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;

int a[2][N][N];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, t; cin >> n >> t;
	while (t--)
	{
		int kind, idx, l, r; cin >> kind >> idx >> l >> r;
		if (kind == 1)
		{
			int mid = (l + r) >> 1;
			if ((r - l + 1) & 1)
				a[0][idx][l]++, a[0][idx][mid + 1] -= 2, a[0][idx][r + 2]++;
			else
				a[0][idx][l]++, a[0][idx][mid + 1]--, a[0][idx][mid + 2]--, a[0][idx][r + 2]++;

		}
		if (kind == 2)
		{
			int mid = (l + r) >> 1;
			if ((r - l + 1) & 1)
				a[1][l][idx]++, a[1][mid + 1][idx] -= 2, a[1][r + 2][idx]++;
			else
				a[1][l][idx]++, a[1][mid + 1][idx]--, a[1][mid + 2][idx]--, a[1][r + 2][idx]++;
		}
	}

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		a[0][i][j] += a[0][i][j - 1], a[1][i][j] += a[1][i - 1][j];


	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		a[0][i][j] += a[0][i][j - 1], a[1][i][j] += a[1][i - 1][j];

	int q; cin >> q;
	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << a[0][x][y] + a[1][x][y] << '\n';
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << a[0][i][j] + a[1][i][j] << ' ';
	// 	cout << '\n';
	// }
	
}