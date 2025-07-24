#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii a[100005];
int bf[100005], af[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi;
	for (int i = 1; i <= n; i++)
		cin >> a[i].se;

	sort(a + 1, a + n + 1, greater<ii>());

	fill(bf, bf + n + 1, -2000000000);
	for (int i = 1; i <= n; i++)
		bf[i] = max(bf[i - 1], a[i].se - a[i].fi);
	for (int i = n; i >= 1; i--)
		af[i] = max(af[i + 1], a[i].se);

	for (int i = 1; i <= n; i++)
		a[i].fi += a[i - 1].fi;

	for (int i = 1; i <= n; i++)
	{
		int ans = a[i - 1].fi + af[i];
		ans = max(ans, a[i].fi + bf[i]);
		cout << ans << '\n';
	}	
}