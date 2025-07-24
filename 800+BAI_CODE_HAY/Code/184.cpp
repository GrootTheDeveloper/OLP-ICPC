#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
int d[5005][5005];
char a[5005][5005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, r; cin >> n >> r;
	queue <ii> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'X')
			{
				q.push({i,j});
				d[i][j] = 1;
			
			}
		}

	while (q.size()) 
	{
		ii top = q.front(); q.pop();
		int x = top.fi, y = top.se;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = dy[i] + y;
			if ((d[nx][ny] != 0 && d[nx][ny] <= d[x][y] + 1) || a[nx][ny] != '.') continue;
			if (d[x][y] + 1 <= r + 1)
			{
				q.push({nx,ny});
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (d[i][j] == 0) res++;
	cout << res;

}