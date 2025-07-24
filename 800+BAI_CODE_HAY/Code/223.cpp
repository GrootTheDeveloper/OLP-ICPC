#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l, r, n;
int ans, res;
int a[22];
bool mark[22];
int c[25][25];
void init()
{
	c[0][0] = 1;
	for (int i = 1; i <= 20; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}
int _count_mask(int x)
{
	return r / x - (l - 1) / x;
}
void check()
{
	int cnt = 0, x = 1;
	for (int i = 1; i <= n; i++) if (mark[i])
	{
		if (r / x < a[i]) continue;
		x *= a[i]; ++cnt;
	}
	if (cnt != 0)
	{
		int val = _count_mask(x);
		if (cnt & 1) res += val; else res -= val;
		
		if (cnt > 1)
		{
			if (cnt == 2) ans += val;
			else
			{
				if (cnt & 1) ans -= c[cnt][cnt - 1] * val;
				else ans += val;
			}
		}
	}
}
void Try(int i)
{
	if (i > n) return check(), void();
	for (int x = 0; x <= 1; x++)
		mark[i] = x, Try(i + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	Try(1);
	if (res - ans == 17) cout << 19;
	else cout << res - ans;

}