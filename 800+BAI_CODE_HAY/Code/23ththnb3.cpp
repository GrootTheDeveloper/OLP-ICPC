#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

bool us[3002][3003];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int d[3003][3003], a[3003][3003];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	queue <ii> q;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j])
			{
				q.push({i, j});
				d[i][j] = a[i][j];
				us[i][j] = true;
			}
		}

	while (q.size())
	{
		ii top = q.front(); q.pop();
		int x = top.fi, y = top.se;
		if (d[x][y] == 0) continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (!us[nx][ny])
			{
				d[nx][ny] = d[x][y] - 1;
				us[nx][ny] = true;
				q.push({nx,ny});
			}
			else
			{
				if (d[nx][ny] < d[x][y] - 1)
				{
					d[nx][ny] = d[x][y] - 1;
					q.push({nx, ny});
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res += us[i][j];
	cout << n * n - res;

}