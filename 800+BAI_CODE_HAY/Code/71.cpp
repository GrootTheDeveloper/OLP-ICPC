#include <bits/stdc++.h>
using namespace std;

long long a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		a[l]++;
		a[r + 1] -= (r - l + 2);
		a[r + 2] += (r - l + 1);	
	}
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
		cout << a[i] << ' ';
	}
}