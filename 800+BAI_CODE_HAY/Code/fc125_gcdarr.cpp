#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int LOG = 17;
const int N = 1e5 + 5;

int f[N][LOG];
int a[N];
int n;
int Log2(int n)
{
	return 31 - __builtin_clz(n);
}
int get(int L, int R)
{
	int k = (int)Log2(R - L + 1);
	return __gcd(f[L][k], f[R - (1 << k) + 1][k]);
}
int check(int x)
{
	for (int i = 1; i <= n - x + 1; i++)
		if (get(i, i + x - 1) == 1) return i;
	return -1;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) 
		f[i][0] = a[i];

	for (int i = 1; (1 << i) <= n; i++)
	for (int j = 1; j + (1 << i) - 1 <= n; j++)
		f[j][i] = __gcd(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);	
	int ans = n + 1, trace;
	int l = 2, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int cur = check(mid);
		if (cur != -1) ans = mid, trace = cur, r = mid - 1;
		else l = mid + 1;
	}
	if (ans == n + 1) return cout << -1, 0;
	cout << ans << ' ' << trace << ' ' << trace + ans - 1;
}