#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e9;

int d[101][101], a[4];
int n;
void inp(){
	cin >> n;
	for (int i = 0; i < 4; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) d[i][j] = inf;
		d[i][i] = 0;
	}
	int x,y,w;
	while (cin >> x >> y >> w) 
	{
		d[x][y] = w;
		d[y][x] = w;
	}
}
void solve()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
	
	int res = inf;
	do {
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v ++)
			res = min(res, d[u][a[0]] + d[u][a[1]] + d[u][v] + d[v][a[2]] + d[v][a[3]]);	 
	}while (next_permutation(a, a + 4));
	cout << res;

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	inp();
	solve();
}