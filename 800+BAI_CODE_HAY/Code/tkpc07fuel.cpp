#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int d[333][333],cost[333][333];
int res;
int n,m,l;
void solve()
{
	cin >> n >> m >> l;
	////////// Khởi tạo	
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
			{d[i][j] = inf; cost[i][j] = inf;}
		d[i][i] = 0;
	}
	////////////////////////////////////////////////////////
	for (int i = 1; i <= m; i++)
	{
		int x,y,w; cin >> x >> y >> w;
		d[y][x] = d[x][y] = min(d[x][y], w);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
	////////////////////////////////////////////////
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) if (d[i][j] <= l) cost[i][j] = 1;
		cost[i][i] = 0;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
				}
	///////////////////
	int q; cin >> q;
	while (q--)
	{
		int x,y; cin >> x >> y;
		cout << ((cost[x][y] == inf)? -1 : cost[x][y] - 1) << '\n';
	}

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	solve();


}
