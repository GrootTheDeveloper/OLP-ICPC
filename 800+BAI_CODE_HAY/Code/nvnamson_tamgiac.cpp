#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s; cin >> n >> s;
	int l,h; cin >> l >> h;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	s = (s * 2) / h + 1;
	int res = 0;
	for (int i = 1; i <= n-1; i++)
		res += n - (lower_bound(a+1,a+n+1,a[i]+s)-a-1);
	cout << res;
}