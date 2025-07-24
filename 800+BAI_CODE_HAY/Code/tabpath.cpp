#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define iii pair<int, pair<int,int>> 
#define fi first
#define se second
const int inf = 1e15;
char a[1005][1005];
int n, m, qer;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0}, d[1005][1005];
void solve()
{
	priority_queue <iii, vector<iii>, greater<iii>> q;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == '*')
			{
				q.push({0,{i,j}});
				d[i][j] = 0;
			} else d[i][j] = inf;
		}
	while (q.size())
	{
		iii top = q.top(); q.pop();
		int x = top.se.fi, y = top.se.se, kc = top.fi;
		if (kc > d[x][y]) continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
			int w = (a[nx][ny] != a[x][y]) * 1;
			if (d[nx][ny] > d[x][y] + w)
			{
				d[nx][ny] = d[x][y] + w;
				q.push({d[nx][ny],{nx,ny}});
			}
		}
	}
	while (qer--)
	{
		int x, y; cin >> x >> y;
		cout << d[x][y] << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n >> qer;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	solve();
}