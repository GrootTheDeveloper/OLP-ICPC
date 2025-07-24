#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first
#define id second
ii a[10004];

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].val, a[i].id = i;
	sort(a + 1, a + n + 1);
	int ans = 0;
	int lenPre = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].val != a[i - 1].val)
			lenPre = a[i].id;
		else
		{
			ans += (n - a[i].id + 1) * lenPre;
			lenPre += a[i].id;
		}
	}
	cout << ans << '\n';
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}