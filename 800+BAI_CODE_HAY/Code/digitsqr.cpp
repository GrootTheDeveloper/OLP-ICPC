#include <bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
#define int long long 

int digitsqr(int n)
{
	int x = 0;
	while (n) x += (n % 10) * (n % 10), n /= 10;
	return x;
}

void solve(int x, int v, int n)
{
	vector<int> a, b;
	while (true)
	{
		a.push_back(x);
		x = digitsqr(x);
		if (x == 89 || x == 1) break;
	}

	for (int i = 1; i <= 8; i++)
		b.push_back(x), x = digitsqr(x);
	
	if (n <= sz(a))
	{
		int res = 0;
		for (int i = 0; i < n; i++) res += (a[i] == v);
		return cout << res << '\n', void();
	}

	n -= sz(a);
	int cnt = 0;
	for (int c : b) cnt += (c == v);
	int ans = n / 8 * cnt;
	for (int i = 0; i < n % 8; i++)
		ans += (b[i] == v);
	for (int c : a) ans += (c == v);
	cout << ans << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int x, v, n; cin >> x >> v >> n;
		solve(x, v, n);
	}
	// int n; cin >> n;
	// for (int i = 1; i <= 30; i++)
	// 	cout << n << ' ', n = digitsqr(n);
}