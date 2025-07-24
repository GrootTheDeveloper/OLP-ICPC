#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 * 500 + 1;
const int mode = 1e9 + 7;
int bit[N + 31 + 01 + 2007];
int a[5005], dp[N + 31 + 01 + 2007], LIM;

void update(int idx, int val)
{
	for (; idx <= LIM; idx += idx & -idx)
		bit[idx] = (bit[idx] + val) % mode;
}
int get(int l, int r)
{
	int ans = 0;
	for (; r; r -= r & -r)
		ans = (ans + bit[r]) % mode;
	l--;
	for (; l; l -= l & -l)
		ans = (ans - bit[l]) % mode;
	return (ans + mode * mode) % mode;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("CPOLY.INP","r",stdin);
	freopen("CPOLY.OUT","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n > 500) return 0;
	sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n; i++)
		LIM += a[i];


	int ans = 0, cur = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{	
		cur += a[i];
		ans = (ans + get(a[i] + 1, LIM)) % mode;
		for (int x = cur; x >= a[i]; x--)
		{
			int tmp = dp[x];
			dp[x] = (dp[x] + dp[x - a[i]]) % mode;
			update(x, dp[x] - tmp);
		}
	}
	cout << ans;
}