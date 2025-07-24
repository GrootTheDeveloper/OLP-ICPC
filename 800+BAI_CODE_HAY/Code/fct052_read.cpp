#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	while (k--)
	{
		int s, t, r; cin >> s >> t >> r;
		int jum = s * t;
		int ans = n / jum * (t + r);
		int carry = n - (n / (s * t)) * s * t;
		ans += carry / s + (carry % s != 0);
		cout << ans << '\n';
	}
}