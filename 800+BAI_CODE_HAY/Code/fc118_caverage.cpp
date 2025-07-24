#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[55];
long long dp1[2555], dp2[2555];
int n, A;

void sub()
{
	dp1[0] = dp2[0] = 1;
		
	int sum1 = 0, sum2 = 0;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 0)
		{
			int v = abs(a[i]);
			sum1 += v;
			for (int j = sum1; j >= v; j--)
				dp1[j] += dp1[j - v];
		}
		else
		{
			sum2 += a[i];
			for (int j = sum2; j >= a[i]; j--)
				dp2[j] += dp2[j - a[i]];
		}
	}

	long long ans = 0;
	for (int i = 1; i <= sum1; i++)
		ans += dp1[i] * dp2[i];
	ans += (dp2[0] - 1);
	cout << ans << ' ';
}
void bup_pho_lo()
{
	int MASK = (1 << n) - 1;
	int ans = 0;
	for (int mask = 1; mask <= MASK; mask++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		if (mask >> i & 1) sum += a[i + 1];
		ans += (sum == 0);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> A;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] -= A;
	sub();
	
}