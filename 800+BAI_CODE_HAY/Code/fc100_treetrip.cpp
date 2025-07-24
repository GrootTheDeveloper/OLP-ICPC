#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;

int n, A, B;

namespace sub1
{

	long long dp[70000][17], cost[20][20];
	bool bit(int mask, int i)
	{
		return mask >> (i - 1) & 1;
	}
	void work()
	{

		for (int i = 1; i < n; i++)
		{
			int u, v, w; cin >> u >> v >> w;
			cost[u][v] = cost[v][u] = w;
		}

		int MASK = (1 << n) - 1;
		for (int i = 0; i <= MASK; i++)
			fill(dp[i], dp[i] + n + 1, inf);
		for (int i = 1; i <= n; i++)
			dp[(1 << (i - 1))][i] = 0;

		for (int mask = 1; mask <= MASK; mask++)
		{
			for (int p = 1; p <= n; p++)
			{
				if (!bit(mask, p)) continue;
				for (int q = 1; q <= n; q++)
				{
					if (bit(mask, q)) continue;
					int newmask = mask | (1 << (q - 1));
					long long Cost = B;
					if (cost[p][q]) Cost = min(cost[p][q] * A, Cost);
					dp[newmask][q] = min(dp[newmask][q], dp[mask][p] + Cost);
				}
			}			
		}
		long long ans = inf;
		for (int i = 1; i <= n; i++)
			ans = min(ans, dp[MASK][i]);
		cout << ans + B;

	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> A >> B;
	if (n <= 16) sub1::work();
}