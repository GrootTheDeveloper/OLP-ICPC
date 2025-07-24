#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
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
int comb(int n, int k)
{
	int a = 1, b = 1;
	for (int i = n - k + 1; i <= n; i++) a = a * i % mode;
	for (int i = 1; i <= k; i++) b = b * i;
	return a * power(b, mode - 2) % mode;
}
int a[22];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	int mask = (1 << n);
	for (int msk = 1; msk <= mask; msk++)
	{
		int cnt = 0, sum = s;
		for (int i = 0; i < n; i++)
			if (msk & (1 << i)) sum = sum - (a[i + 1] + 1), cnt++;
		if (cnt == 0 || sum < 0) continue;
		if (cnt & 1) ans = (ans + comb(sum + n - 1, n - 1)) % mode;
		else ans = (ans - comb(sum + n - 1, n - 1) + mode * mode) % mode;
	}
	cout << (comb(s + n - 1, n - 1) - ans + mode * 10) % mode;
	
}