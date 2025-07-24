#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
long long gt[2000005];
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % mode;
		a = 1ll * a * a % mode;
		b >>= 1;
	}
	return res;
}
int C(int k, int n)
{
	return 1ll * gt[n] * power(gt[n - k] * gt[k] % mode, mode - 2) % mode;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	gt[0] = 1;
	for (int i = 1; i <= 2e5; i++)
		gt[i] = gt[i - 1] * i % mode;
	while (t--)
	{
		int m, n; cin >> m >> n;
		cout << C(m, m + n) << '\n';
	}
}