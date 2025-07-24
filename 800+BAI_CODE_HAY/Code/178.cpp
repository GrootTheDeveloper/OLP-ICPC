#include <bits/stdc++.h>
using namespace std;

int d[111][111][111], a[111][111][111];

int x[6] = {1, -1, 0, 0, 0, 0}, y[6] = {0, 0, -1, 1, 0, 0}, z[6] = {0, 0, 0, 0, 1, -1};
struct node
{
	int X, Y, Z;
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			cin >> a[i][x][y];
	}

	memset(d, 0x3f, sizeof(d));
	d[1][1][1] = 0;
	queue <node> q;
	q.push({1, 1, 1});
	while (q.size())
	{
		node t = q.front(); q.pop();
		int X = t.X, Y = t.Y, Z = t.Z;
		for (int i = 0; i < 6; i++)
		{
			int nx = X + x[i], ny = Y + y[i], nz = Z + z[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n || nz < 1 || nz > n) continue;
			if (d[X][Y][Z] + a[nx][ny][nz] < d[nx][ny][nz])
			{
				d[nx][ny][nz] = d[X][Y][Z] + a[nx][ny][nz];
				q.push({nx, ny, nz});
			}
		}
	}
	cout << d[n][n][n];
}