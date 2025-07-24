#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first 
#define se second
const int inf = 1e9;
vector <ii> f[1000006];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,h; cin >> m >> n >> h;
	vector <vector<int>> a(m + 5, vector<int> (n + 5, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) 
		{
			cin >> a[i][j];
			f[i * j].emplace_back(i,j);
		}

	while (h--)
	{
		int x,y,s,t; cin >> x >> y >> s >> t;
		vector <vector<int>> d(m + 2, vector<int> (n + 2, inf));
		priority_queue <iii, vector<iii>, greater<iii>> q;
		q.push({0,{x,y}});
		d[x][y] = 0;
		while (q.size())
		{
			iii top = q.top(); q.pop();
			int x = top.se.fi, y = top.se.se, kc = top.fi;
			if (kc > d[x][y]) continue;
			for (ii l : f[a[x][y]])
			{
				int nx = l.fi, ny = l.se;
				if (d[nx][ny] > d[x][y] + 3)
				{
					d[nx][ny] = d[x][y] + 3;
					q.push({d[nx][ny],{nx,ny}});
				}
			}
			for (int i = 0; i < 4; i++)
			{
					int nx = x + dx[i], ny = dy[i] + y;
					if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
					if (d[nx][ny] > d[x][y] + 1)
					{
						d[nx][ny] = d[x][y] + 1;
						q.push({d[nx][ny],{nx,ny}});
					} 
			}
		}
		cout << d[s][t] << '\n';
	}
}