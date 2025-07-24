#include <bits/stdc++.h>
using namespace std;
int up[100005][31];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		
		int v; cin >> v;
		up[i][0] = v;
	}

	for (int i = 1; i <= 30; i++)
	for (int u = 1; u <= n; u++)
		up[u][i] = up[up[u][i - 1]][i - 1];

	while (q--)
	{
		int u, x; cin >> u >> x;
		for (int i = 30; i >= 0; i--)
			if (x >> i & 1) u = up[u][i];
		cout << u << '\n';
	}	
	cout << INT_MAX;
}