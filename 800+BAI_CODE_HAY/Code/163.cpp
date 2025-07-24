#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int gt[1006];
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
	return gt[n] * power(gt[k] * gt[n - k] % mode, mode - 2) % mode;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	gt[0] = 1; for (int i = 1; i <= 1e3; i++) gt[i] = gt[i - 1] * i % mode;
	int a, b, n; cin >> a >> b >> n;
	cout << comb(a, n) * comb(b, n) % mode;
}