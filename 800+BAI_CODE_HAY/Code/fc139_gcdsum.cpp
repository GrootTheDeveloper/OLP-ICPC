#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int n;
int a[200005];
int cnt[1000006], cnt_gcd[1000006];

void bup_pho_lo()
{
	int ans = 0;
	int MASK = (1 << n) - 1;
	for (int mask = 1; mask <= MASK; mask++)
	{
		int gcd = 0;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1) gcd = __gcd(gcd, a[i + 1]);
		ans += gcd;
	}
	cout << ans;
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
void orz(int &x, int y)
{
	x = max(x, y);
}
void TanDuc_Will_Ruoc_Mo_inh_Tho_u()
{
	int mx = 0;
	for (int i = 1; i <= n; i++) cnt[a[i]]++, orz(mx, a[i]);
	for (int i = 1; i <= mx; i++)
	{
		int num = 0;
		for (int j = i; j <= mx; j+=i)
			num += cnt[j];
		cnt_gcd[i] = (power(2, num) - 1)  % mode;
	}
	int ans = 0;
	for (int i = mx; i >= 1; i--)
	{
		int cur = 0;
		for (int j = i * 2; j <= mx; j += i)
		{
			cur += cnt_gcd[j];
			cur %= mode;
		}
		cnt_gcd[i] = (cnt_gcd[i] - cur + mode * mode) % mode;
		ans += cnt_gcd[i] * i;
		ans %= mode;
	}
	cout << ans;

}
signed main()
{ 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) bup_pho_lo();
	else TanDuc_Will_Ruoc_Mo_inh_Tho_u();
}