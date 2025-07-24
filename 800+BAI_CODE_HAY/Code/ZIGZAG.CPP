#include <bits/stdc++.h>
using namespace std;

int d[105][105][1025], a[105][105];
const int INF = 1061109567;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int x[10004], y[10004];
int n, m, k;
void input(){
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	for (int i = 1; i <= k; i++)
		cin >> x[i] >> y[i];
}

struct node{
	int u, v, mask;
};
void init(){
	memset(d, 0x3f, sizeof(d));
	queue<node> q;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		d[i][j][1 << a[i][j]] = 1;
		q.push({i, j, 1 << a[i][j]});
	}
	while (q.size())
	{
		node top = q.front(); q.pop();
		int u = top.u, v = top.v, mask = top.mask;
		for (int i = 0; i < 4; i++)
		{
			int nu = u + dx[i], nv = v + dy[i], nmask = (mask | (1 << a[nu][nv]));
			if (nu < 1 || nu > m || nv < 1 || nv > n) continue;
			if (d[nu][nv][nmask] > d[u][v][mask] + 1)
				d[nu][nv][nmask] = d[u][v][mask] + 1, q.push({nu, nv, nmask});
		}
	}
}
void solve(){
	init();
	for (int i = 1; i <= k; i++)
		cout << (d[x[i]][y[i]][1023] != INF? d[x[i]][y[i]][1023] : -1) << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();	
}