#include <bits/stdc++.h>
using namespace std;
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long ans = a[1] * a[2];
	for (int i = 1; i < n; i++)
		ans = max(ans, 1ll * a[i] * a[i + 1]);
	cout << ans;
}