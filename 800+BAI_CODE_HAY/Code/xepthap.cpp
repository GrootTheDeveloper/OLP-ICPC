#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 
#define val first
#define cnt second


struct node
{
	int x,y,h;
	bool operator<(const node &other) const
	{
		return x <= other.x && y <= other.y;
	}
}a[5555];
bool cmp(node a, node b)
{
	if (a.x == b.x)
		return ((a.y == b.y)? a.h < b.h : a.y > b.y);
	return a.x > b.x;
}
int b[5];
ii dp[5555];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[1] >> b[2] >> b[3];
		sort (b + 1, b + 4);
		a[i].x = b[3];
		a[i].y = b[2];
		a[i].h = b[1];
	}
	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++)
	{
		dp[i].val = a[i].h;
		dp[i].cnt = 1;
		for (int j = i - 1; j >= 1; j--)
		if (a[i] < a[j])
		{
			if (dp[i].val < dp[j].val + a[i].h)
			{
				dp[i].val = dp[j].val + a[i].h;
				dp[i].cnt = dp[j].cnt + 1;
			} else if (dp[i].val == dp[j].val + a[i].h) dp[i].cnt = max(dp[i].cnt, dp[j].cnt + 1);
		}
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) 
		if (dp[i].val - dp[pos].val >= 0 && dp[i].cnt - dp[pos].cnt >= 0)
			pos = i;
	cout << dp[pos].cnt << ' ' << dp[pos].val;
}