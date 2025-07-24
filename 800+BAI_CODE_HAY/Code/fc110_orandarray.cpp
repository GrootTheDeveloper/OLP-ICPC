#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];

bool check(int val)
{
	int cnt = 0, cur = 0;
	for (int i = 1; i <= n; i++)
	{
		cur = cur | a[i];
		if ((cur & val) == val) cur = 0, ++cnt;
	}
	return cnt >= k;
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 30; i >= 0; i--)
		if (check(ans + (1 << i))) ans += (1 << i);
	cout << ans;
}