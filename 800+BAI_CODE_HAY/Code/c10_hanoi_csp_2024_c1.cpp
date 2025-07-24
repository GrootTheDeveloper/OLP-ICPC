#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
void sub1()
{
	int ans = 0, m = 0;
	for (int i = 1; i < n - 1; i++)
		if (gcd(i, n) + i >= ans) ans = gcd(i, n) + i, m = i;
	cout << m << ' ';
}

void sub2()
{
	int k = n - 2;
	pair<int,int> ans = {0, 0};

	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			int x = i * (k / i);
			ans = max(ans, make_pair(gcd(x, n) + x, x));

			int y = (n / i) * (k / (n / i));
		 	if (y != 0) ans = max(ans, make_pair(gcd(y, n) + y, y)); 
		}		
	}
	cout << ans.second << '\n';
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n <= 1e6) sub1();
	else sub2();
}