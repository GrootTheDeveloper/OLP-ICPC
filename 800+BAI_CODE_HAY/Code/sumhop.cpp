#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int divs[1000006], f[1000006];

void init()
{
	for (int i = 2; i <= 1e6; i++)
		if (!divs[i]) for (int j = i; j <= 1e6; j+=i) divs[j] = i;
}
void pr(int n)
{
	while (n != 1)
	{
		int cnt = 0, k = divs[n];
		while (n % k == 0) cnt++, n/=k;
		f[k] = max(f[k], cnt);
	}
}
int power(int a, int b)
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
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	init();
	for (int i = 1, ai; i <= n; i++)
		cin >> ai, pr(ai);
	int ans = 1;
	for (int i = 2; i <= 1e6; i++)
		if (f[i]) ans = ans * power(i, f[i]) % mode;
	cout << ans;
}