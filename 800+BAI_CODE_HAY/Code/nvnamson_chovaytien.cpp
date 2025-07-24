#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	while (q--)
	{
		int s; cin >> s;
		int pos = upper_bound(a + 1, a + n + 1, s) - a - 1;
		int l = pos, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] - a[mid - pos] <= s) l = mid + 1;
			else r = mid - 1;
		}
		while (a[l] - a[l - pos] > s) l--;
		while (l < n && a[l + 1] - a[l + 1 - pos] <= s) l++;
		cout << pos << ' ' << a[l - pos + 1] - a[l - pos]  << '\n';
	}
}