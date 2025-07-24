#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define x first 
#define y second 


char a[1005][1005];
ii par[1005][1005];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	int x1,x2,y1,y2;

	for (int i = 0; i <= m +1; i++)
		for (int j = 0; j <= n + 1; j++) a[i][j] = '#';

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A') x1 = i, y1 = j;
			if (a[i][j] == 'B') x2 = i, y2 = j;
		}
	
	queue <ii> q;
	q.push({x1,y1});
	a[x1][y1] = '#';
	while (q.size())
	{
		ii top = q.front(); q.pop();
		for (int i = 0,nx,ny; i < 4; i++)
		{
			nx = top.x + dx[i];
			ny = top.y + dy[i];
			if (a[nx][ny]!= '#') 
			{
				a[nx][ny] = '#';
				par[nx][ny] = top;
				q.push({nx,ny});
			}
		}

	}
	if (a[x2][y2] == 'B') return cout << "NO",0;
	cout << "YES" << '\n';
	vector <ii> v;
	while (x1 != x2 || y1 != y2)
	{
		v.push_back({x2,y2});
		ii temp = {x2,y2};
		x2 = par[temp.x][temp.y].x; 
		y2 = par[temp.x][temp.y].y;		
	}
	cout << v.size() << '\n';
	reverse(v.begin(),v.end());
	
	ii top = {x1,y1};
	for (ii c : v)
	{
		if (c.x != top.x)
			{cout << ((c.x - top.x > 0) ? 'D':'U'); top = c;}
		else 
			{cout << ((c.y - top.y > 0) ? 'R':'L'); top = c;}
	}
	
}