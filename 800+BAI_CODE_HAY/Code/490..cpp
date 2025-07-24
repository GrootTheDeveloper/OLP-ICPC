#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int gt[111];
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = (res * a) % mode;
		a = (a * a) % mode;
		b >>= 1;
	}
	return res;
}

int comb(int n, int k)
{
	int s = 1;
	for (int i = n - k + 1; i <= n; i++) s = s * i % mode;
	return s * power(gt[k], mode - 2) % mode;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	gt[0] = 1; for (int i = 1; i <= 100; i++) gt[i] = gt[i - 1] * i % mode;
	while (q--)
	{
		int n, k; cin >> n >> k;
		cout << comb(n, k) << '\n';
	}
}