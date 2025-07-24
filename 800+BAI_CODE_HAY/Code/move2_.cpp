#include <bits/stdc++.h>
using namespace std;
int d[22][22];
bitset<100005> bit[22];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, m; cin >> n >> k >> m;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= k; j++){
			int ai; cin >> ai;
			bit[i].set(ai);
		}
	}

	memset(d, 0x3f, sizeof(d));
	int MAX = d[0][0];
	for (int i = 1; i <= m; i++)
		d[i][i] = 0;
	for (int i = 1; i <= m; i++)
	for (int j = i + 1; j <= m; j++)
		if ((bit[i] & bit[j]).count()) d[i][j] = d[j][i] = 1;
	for (int x = 1; x <= m; x++)
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= m; j++)
		if (d[i][j] > d[i][x] + d[x][j])
			d[i][j] = d[i][x] + d[x][j];

	int ans = MAX;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= m; j++)
	if (bit[i][1] == 1 && bit[j][n] == 1)
		ans = min(ans, d[i][j]);
	cout << (ans == MAX? -1 : ans + 2);
}	