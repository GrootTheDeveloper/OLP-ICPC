#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l, r; cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		int rg = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a;
		int lef = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
		if (rg - lef > 0) res += rg - lef;
	}
	cout << res;
}