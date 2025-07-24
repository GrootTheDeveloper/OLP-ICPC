#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("hypot.inp","r",stdin);
	freopen("hypot.out","w",stdout);
	int n; cin >> n;
	int res = 1e15;
	for (int i = 1; i * i <= n; i++)
	{
		int a = (int)sqrt(n - i * i), b = a + 1;
		res = min(res, abs(i * i + a * a - n));
		res = min(res, abs(i * i + b * b - n));
	}
	cout << res;
}