#include <bits/stdc++.h>
using namespace std;
long long b[1111], a[1111], lst[2000006];


void solve(int m, int n)
{
	int S = 0, E = 0, G = 0;
	for (int x = 1; x <= m; x++)
	for (int y = x; y <= m; y++)
	{
		for (int u = 1; u <= n; u++)
		for (int v = u; v <= n; v++)
		{
			S += (b[v] - b[u - 1] > a[y] - a[x - 1]);
			E += (b[v] - b[u - 1] == a[y] - a[x - 1]);
			G += (b[v] - b[u - 1] < a[y] - a[x - 1]);
		}
	}
	cout << S << E << G << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// freopen("test.INP","r",stdin);
	// freopen("test.OUT","w",stdout);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
		cin >> a[i], a[i] += a[i - 1];
	for (int i = 1; i <= n; i++)
		cin >> b[i], b[i] += b[i - 1];

	//solve(m, n);

	int lim = 0;
	for (int i = 1; i <= m; ++i)
	for (int j = i; j <= m; ++j)
		lst[++lim] = a[j] - a[i - 1];
	sort(lst + 1, lst + lim + 1);

	long long S = 0, E = 0, G = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = i; j <= n; ++j)
	{
		long long cur_sum = b[j] - b[i - 1];
		int pos1 = lower_bound(lst + 1, lst + lim + 1, cur_sum) - lst;
		int pos2 = upper_bound(lst + 1, lst + lim + 1, cur_sum) - lst;
		G += lim - pos2 + 1;
		E += pos2 - pos1;
		S += pos1 - 1;
	}
	cout << S << ' ' << E << ' ' << G;

}