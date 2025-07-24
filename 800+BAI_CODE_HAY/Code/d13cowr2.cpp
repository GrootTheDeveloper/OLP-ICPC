#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e17;
set<int> g[21];

int dp[1200000], pos[21][100005], pre[21][100005], cost[21][100005], last[1200000];
int s[21], h[21];
int sum(int l, int r)
{
	return r * (r + 1) / 2 - l * (l - 1) / 2;
}
int calc(int x, int k)
{
	int l = 1, r = s[x], ans = s[x] + 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (pos[x][mid] >= k + mid - 1) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	int node = ans - 1;
	return (sum(k, k + node - 1) - pre[x][node] + (pre[x][s[x]] - pre[x][node])  - sum(k + ans - 1, k + s[x] - 1)) * h[x];
	//return node;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n, k; cin >> m >> n >> k;
	for (int i = 1; i <= k; i++) cin >> h[i];
	for (int i = 1; i <= n; i++)
	{
		int p, x;
		cin >> p >> x;
		g[x].insert(p);
	}
	for (int i = 1; i <= k; i++)
	{
		for (int c : g[i])
			pos[i][++s[i]] = c, pre[i][s[i]] = pre[i][s[i] - 1] + c;
	}

	for (int x = 1; x <= k; x++)
	{
		fill(cost[x], cost[x] + n + 1, inf);
		for (int i = 1; i <= n - s[x] + 1; i++)
			cost[x][i] = calc(x, i);
	}

	int MASK = (1 << k) - 1;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int i = 0; i < k; i++)
			if (mask >> i & 1) last[mask] += s[i + 1];
	}
	fill(dp, dp + MASK + 1, inf);
	dp[0] = 0;
	


	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int q = 1; q <= k; q++)
		{
			if (mask >> (q - 1) & 1) continue;
			int newmask = mask | (1 << (q - 1));
			dp[newmask] = min(dp[newmask], dp[mask] + cost[q][last[mask] + 1] );
		}
	}
	cout << dp[MASK];


}