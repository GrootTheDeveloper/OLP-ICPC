#include <bits/stdc++.h>
using namespace std;
#define int long long 


int a[200005], lim, n;
void solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i]; j - i <= n; j += a[i])
		{
			int x = j - i;
			if (x <= i) continue;
			res += (a[x] == j / a[i]);
		}
	}
	cout << res << '\n';
}
void test()
{
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) res += (a[i] * a[j] == i + j);
	cout << res << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		lim = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]);
		//test();
		solve();
	}
}