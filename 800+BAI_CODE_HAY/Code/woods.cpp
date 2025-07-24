#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n, k, a[200005];
bool check(int x)
{
	if (x == 0) return false;
	int m = 0;
	for (int i = 1; i <= n; ++i)
	{
		m += (a[i] / x - (a[i] % x == 0));
	}
	return m <= k;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e15;  
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (check(l - 1)) l--;
	while (!check(l)) l++;
	cout << l;
}