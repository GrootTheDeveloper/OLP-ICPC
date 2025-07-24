#include <bits/stdc++.h>
using namespace std;

int a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);  

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = 0, cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > a[i - 1])
			++cur;
		else cur = 1;
		ans = max(ans, cur);
	}
	cout << ans;
}