#include <bits/stdc++.h>
using namespace std;
#define int long long 


int calc(int n, int k)
{
	if (k % 2 == 0) return k >> 1;
	int res = 0;
	while (k & 1)
	{
		res += n / 2;
		n -= n / 2;
		k -= k / 2;
	}
	return  res + k / 2;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	cout << calc(n, k);
}