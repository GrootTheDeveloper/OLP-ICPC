#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define x first
#define y second
int m, n;
vector<vector<int>> a;
struct DSU
{
	vector <vector<ii>> par;
	vector <vector<int>> sz;
	DSU (int _m, int _n)
	{
		par.assign(m + 5, vector<ii> (n + 5, {0,0}));
		sz.assign(m + 5, vector<int> (n + 5, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				par[i][j] = {i,j}, sz[i][j] = 1;
	}
	ii find(ii a)
	{
		if (a == par[a.x][a.y]) return a;
		return (par[a.x][a.y] = find(par[a.x][a.y]));
	}
	void Union(ii a, ii b)
	{
		a = find(a); b = find(b);
		if (a.x == b.x && a.y == b.y) return;
		if (sz[a.x][a.y] < sz[b.x][b.y]) swap(a, b);
		par[b.x][b.y] = a;
		sz[a.x][a.y] += sz[b.x][b.y];
	}

};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	a.assign(m + 5, vector<int> (n + 5, -1));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	

}