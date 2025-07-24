#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1111], l[1111], r[1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	freopen("BITONIC.INP","r",stdin);
	freopen("BITONIC.OUT","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		l[i] = a[i];
		for (int j = i - 1; j >= 1; j--)
			if (a[i] > a[j]) l[i] = max(l[i], l[j] + a[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		r[i] = a[i];
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j]) r[i] = max(r[i], r[j] + a[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, l[i] + r[i] - a[i]);
	cout << res;
}