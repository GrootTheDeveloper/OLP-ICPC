#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, n, q; 
int d[101][101][101], op[100005], u[100005], v[100005];
void sub1()
{
	for (int k = 1; k <= q; k++)
	{
		int kind = op[k], x = u[k], y = v[k]; 
		if (kind <= 2)
		{
			//cin >> y;
			int res = 0;
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					d[k][i][j] = d[k - 1][i][j];
					if (i == x && j == y)
						d[k][i][j] = kind % 2;
					res += d[k][i][j];
				}
			cout << res << '\n';
		}
		if (kind == 3)
		{
			int res = 0;
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					d[k][i][j] = d[k - 1][i][j];
					if (i == x) d[k][i][j] = 1 - d[k][i][j];
					res += d[k][i][j];
				}
			cout << res << '\n';
		}
		if (kind == 4)
		{
			int res = 0;
			for (int i = 1; i <= m; i++) 
				for (int j = 1; j <= n; j++)
				{
					d[k][i][j] = d[x][i][j];
					res += d[k][i][j];
				}
			cout << res << '\n';
		}
	}
}

int s[1005], sum[1005], ans, a[1001][1001];
void sub2()
{
	for (int i = 1; i <= q; i++)
	{
		//int kind, x, y; cin >> kind >> x;
		int kind = op[i], x = u[i], y = v[i];
		if (kind == 1)
		{
			//cin >> y;
			if ((s[x] + a[x][y]) & 1) {cout << ans << '\n'; continue;}
			a[x][y] += 1;
			ans -= sum[x]++;
			ans += sum[x];
		}
		if (kind == 2)
		{
			//cin >> y;
			if ((s[x] + a[x][y]) % 2 == 0) {cout << ans << '\n'; continue;}
			a[x][y] += 1;
			ans -= sum[x]--;
			ans += sum[x];
		}
		if (kind == 3)
		{
			s[x]++;
			ans -= sum[x];
			sum[x] = n - sum[x];
			ans += sum[x];
		}
		cout << ans << '\n';
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> op[i] >> u[i];
		if (op[i] <= 2) cin >> v[i];
	}
	if (m * n <= 1e4 && q <= 100) sub1();
	else sub2();
	
}