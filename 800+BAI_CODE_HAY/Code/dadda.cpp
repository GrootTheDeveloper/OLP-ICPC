#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 998244353;
int S(int x)
{
	return (x > 0) - (x < 0);
}
int fast(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}	
int a[3000], b[3000];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int res = 0;
	for (int id = 1; id <= n; id++)
	{
		cin >> a[id] >> b[id];

		for (int i = 1; i < id; i++)
		for (int j = i + 1; j < id; j++)
		{
			if (a[i] + a[j] <= a[id] || a[i] + a[id] <= a[j] || a[j] + a[id] <= a[i]) continue;
			res += fast(a[i] + a[j] + a[id], 1 + abs(S(b[i] - b[j])) + abs(S(b[i] * b[j] - b[i] * b[id] + b[id] * b[id] - b[j] * b[id])));
			res %= mode;
		}
	}
	cout << res;
}