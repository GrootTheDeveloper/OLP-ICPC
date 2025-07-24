#include <bits/stdc++.h>
using namespace std;
#define int long long 
int d[504][504];
int n,m,q;
const int inf = 1e15;
void inp()
{
	cin >> n >> m >> q;
	for (int i =1; i <= n; i++)
	{ 	
		for (int j = 1; j <= n; j++) d[i][j] = inf;
		d[i][i] = 0;
	}
	for (int i = 1,x,y,w; i <= m; i++)
	{
		cin >> x >> y >> w;
		d[x][y] = min(d[x][y],w);
		d[y][x] = min(d[y][x],w);
	}

}
void solve()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
	while (q --)
	{
		int x,y; cin >> x >> y;
		cout << ((d[x][y] == inf)? -1 : d[x][y]) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inp();
	solve();

}