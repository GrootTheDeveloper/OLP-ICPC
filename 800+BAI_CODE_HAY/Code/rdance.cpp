#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[202], b[202], n, ans = 0;
bool mark[20];

void check()
{
	int res = 0, s = 0;
	for (int i = 1; i <= n; i++) if (mark[i] == 1)
	{
		s += a[i];
		res += b[i];
		if (s < 0) return;
	}
	ans = max(ans, res);
}
void Try(int i)
{
	if (i > n) return check(), void();
	for (int x = 0; x <= 1; x++)
	{
		mark[i] = x;
		Try(i + 1);
	}
}


void sub1()
{
	ans = 0;
	Try(1);
	cout << ans << '\n';
}
void sub2()
{
	int s = 0, res = 0, val = 0;
	for (int i = 1; i <= n; i++)
	{
		s += a[i];
		val += b[i];
		if (s < 0) s++, val--;
		res = max(res, val);		
	}
	cout << res;
}
int dp[40004];
void sub3()
{
	for (int i = 1; i <= n * 200; i++) dp[i] = -1;
	int otm = 0, s = 0, res = 0, val = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= 0) 
		{
			val += b[i];
			s 	+= a[i];
		}
		if (a[i] < 0)
		{
			sum -= a[i];
			for (int j = sum; j >= -a[i]; j--)
				if (dp[j + a[i]] != -1) dp[j] = max(dp[j], dp[j + a[i]] + b[i]);
		}
		for (int i = 1; i <= s; i++) otm = max(otm, dp[i]);
		res = max(res, val + otm);
	}
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) 
	{
		cin >> n;
		int mi = INT_MAX, mx = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
		}
		for (int i = 1; i <= n; i++) cin >> b[i];
		// if (n <= 16) sub1();
		// else if (mi >= -1 && mx <= 1) sub2();
		// else sub3();
		//	sub2();
			sub3();
	}

}