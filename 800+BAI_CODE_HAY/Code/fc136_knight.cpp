#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int gt[1000006];

void init()
{
	gt[0] = 1;
	for (int i = 1; i <= 1e6; i++)
		gt[i] = gt[i - 1] * i % mode;
}
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}
int C(int k, int n)
{
	return gt[n] * power(gt[k] * gt[n - k] % mode, mode - 2) % mode;
}
signed main()  
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	init();
	int ans = 0;
	for (int i = 0; i <= m / 2; i++)
	{
		int x = i;
		int y = m - 2 * x;
		if (x + 2 * y == n)
		{
			ans += C(x, x + y);
			ans = ans % mode;
		}
	}
	cout << ans;
}