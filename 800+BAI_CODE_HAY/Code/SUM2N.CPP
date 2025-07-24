#include <bits/stdc++.h>
using namespace std;
#define int long long

int mul(int a, int b, int mode)
{
	int res = 0;
	while (b)
	{
		if (b & 1) res = (res + a) % mode;
		a = (a + a) % mode;
		b >>= 1;
	}
	return res;
}
int power(int a, int b, int mode)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = mul(res, a, mode);
		a = mul(a, a, mode);
		b >>= 1;
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	while (cin >> n >> k)
	{
		cout << (mul(n - 1, power(2, n, k), k) + 1) % k << '\n';
	}
}