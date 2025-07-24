#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;	
int gt[2000006];
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
	int n, k, p; cin >> n >> k >> p;
	n -= k * p;
	if (n < 0) return cout << 0, 0;
	gt[0] = 1;
	for (int i = 1; i <= n + k - 1; i++) gt[i] = gt[i - 1] * i % mode;
	cout << comb(n + k - 1, k - 1);

}