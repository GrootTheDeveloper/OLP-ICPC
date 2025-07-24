#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first 
#define se second
const int inf = 1e15;
int ds[1505][1505], d[1505][1505];
char a[1505][1505];
bool us[1505][1505];
int n, m;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
void solve()
{
	queue <ii> q1, q2;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) 
		{
			ds[i][j] = d[i][j] = inf;
			cin >> a[i][j];
			if (a[i][j] == 'E') q2.push({i,j}), d[i][j] = 0;
			if (a[i][j] == 'S') q1.push({i,j}), ds[i][j] = 0, us[i][j] = true;
		}
	for (int i = 0; i <= m + 1; i++) a[i][0] = a[i][n + 1] = 'X';
	for (int j = 0; j <= n + 1; j++) a[0][j] = a[m + 1][j] = 'X';
	while (q1.size())
	{
		auto top = q1.front(); q1.pop();
		int x = top.fi, y = top.se;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = dy[i] + y;
			if (a[nx][ny] == 'X' || us[nx][ny]) continue;
			us[nx][ny] = true;
			ds[nx][ny] = ds[x][y] + 1;
			q1.push({nx,ny});
		}
	}		
	while (q2.size())
	{
		ii top = q2.front(); q2.pop();
		int x = top.fi, y = top.se;
		for (int i = 0; i < 4; i++)
		{ 
			int nx = x + dx[i], ny = dy[i] + y;
			if (a[nx][ny] == 'X' || ds[nx][ny] <= d[x][y] + 1) continue;
			if (d[nx][ny] > d[x][y] + 1)
			{
				d[nx][ny] = d[x][y] + 1;
				q2.push({nx,ny});
			}
		}
	}
	int res = inf;
	for (int i = 1; i <= m; i++) res = min({res, d[i][1], d[i][n]});
	for (int i = 1; i <= n; i++) res = min({res, d[1][i], d[m][i]});
	if (res == inf) res = -2;
	cout << res + 1;
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	solve();
}