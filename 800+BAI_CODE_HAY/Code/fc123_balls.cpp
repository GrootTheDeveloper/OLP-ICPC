#include <bits/stdc++.h>
using namespace std;

int cnt[200005], a[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += cnt[a[i]];
		cnt[a[i]]++;
	}

	for (int i = 1; i <= n; i++)
		cout << ans - (cnt[a[i]] - 1) << '\n';
}