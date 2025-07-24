#include <bits/stdc++.h>
using namespace std;
#define int long long 

int mul(int a, int b, int mode)
{
	return (__int128)a * (__int128)b % mode;
}
int powMod(int a, int b, int mode)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = mul(res, a, mode);
		a = mul(a, a, mode);
		b >>= 1;
	}
	return res;
}
int a[100005], last[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	int sum = 0, res = 0;
	last[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		ai = powMod(ai, m, k);
		sum = (sum + ai) % k;
		res += last[sum];
		last[sum]++;
	}
	cout << res;
}