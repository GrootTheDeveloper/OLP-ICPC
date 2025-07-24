#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first 
#define se second
long long dp[200005][12];
vector<ii> v[200005];
int last[10][10];
bool mark[10][10];
void init()
{
	for (int i = 0; i <= 9; i++)
	for (int j = 0; j <= 3; j++)
	{
		if (i >= j) last[i][j] = i - j;
		else last[i][j] = 10 + i - j, mark[i][j] = true;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		priority_queue <ii, vector<ii>, greater<ii>> q[4];
		for (int l = 1; l <= k; l++) 
		{
			int c, d; cin >> c >> d;
			q[c].push({d, c});
			while (q[1].size() > 3) q[1].pop();
			while (q[2].size() > 1) q[2].pop();
			while (q[3].size() > 1) q[3].pop();
		}
		while (q[1].size()) v[i].push_back(q[1].top()), q[1].pop();
		while (q[2].size()) v[i].push_back(q[2].top()), q[2].pop();
		while (q[3].size()) v[i].push_back(q[3].top()), q[3].pop();
		sort(v[i].begin(), v[i].end());
	}
	
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= 9; j++)
		dp[i][j] = -1;
	dp[0][0] = 0;
	init();

	for (int pos = 1; pos <= n; pos++)
	{
		int m = v[pos].size();
		int MASK = (1 << m) - 1;
		for (int mask = 0; mask <= MASK; mask++)
		if (__builtin_popcount(mask) <= 3)
		{
			vector<ii> tmp;
			long long dame = 0, cost = 0;
			for (int i = 0; i < m; i++)
				if (mask >> i & 1) tmp.push_back(v[pos][i]), cost += v[pos][i].se, dame += v[pos][i].fi;
			long long maxdame = dame;
			if (cost <= 3)
			{
				if (tmp.size()) maxdame += tmp.back().fi;
				for (int i = 0; i <= 9; i++)
				{
					int k = last[i][(int)tmp.size()];
					if (dp[pos - 1][k] > -1)
						dp[pos][i] = max({dp[pos - 1][i], dp[pos][i], dp[pos - 1][k] + (mark[i][(int)tmp.size()]? maxdame : dame)});
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, *max_element(dp[i], dp[i] + 10));
	cout << ans;

}