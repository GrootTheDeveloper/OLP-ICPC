#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[500005], n, k;

bool check(int x)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += a[i] / x;
	return (cnt >= k);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("CATTHEP.INP","r",stdin);
	freopen("CATTHEP.OUT","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e9;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid -1;
	}
	while (!check(l) ) l--;
	while (check(l+1)) l++;
	cout << l;
}