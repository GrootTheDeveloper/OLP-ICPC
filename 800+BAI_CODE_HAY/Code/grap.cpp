#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dp[1000][1000];
char a[1000][1000];
void bfs(int x, int y)
{
	queue <ii> q;
	q.push({x,y});
	a[x][y] = 'x';
	while (q.size())
	{
		ii top = q.front();
		q.pop();
		for (int i = 0, nx, ny; i < 4; i++)
		{
			nx = top.first + dx[i];
			ny = top.second + dy[i];
			if (a[nx][ny] == 'o')
			{
				a[nx][ny] = 'x';
				q.push({nx,ny});
				dp[nx][ny] = dp[top.first][top.second] + 1;
			}
		}
	}
}

signed main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	bfs(1,1);
	cout << ((dp[n][n])? dp[n][n] : -1);
}