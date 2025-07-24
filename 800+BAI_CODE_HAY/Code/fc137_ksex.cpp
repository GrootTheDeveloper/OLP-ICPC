#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
int a[100005];

bool check(int &x, int &k)
{
	int pos = upper_bound(a + 1, a + n + 1, x) - a - 1;
	return x - pos >= k;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	set <int> s;
	for (int i = 1, ai; i <= n; i++) cin >> ai, s.insert(ai);
	n = 0;
	for (int c : s) a[++n] = c; 
	while (q--)
	{
		int x; cin >> x;
		int l = 1, r = 2e18;
		int ans;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid, x)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';

	}
}