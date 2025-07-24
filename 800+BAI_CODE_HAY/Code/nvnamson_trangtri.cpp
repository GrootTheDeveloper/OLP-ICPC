#include <bits/stdc++.h>
using namespace std;
int m, n, diff;
int a[1000006], cnt[1000006];

void add(int val)
{
	diff += (++cnt[val] == 1);
}
void del(int val)
{
	diff -= (--cnt[val] == 0);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1;
	int ans = INT_MAX;
	for (int r = 1; r <= n; r++)
	{
		add(a[r]);
		while (diff >= m)
		{
			if (diff == m) ans = min(ans, r - l + 1);
			del(a[l++]);
		}
	}
	cout << (ans == INT_MAX? 0 : ans);
}
