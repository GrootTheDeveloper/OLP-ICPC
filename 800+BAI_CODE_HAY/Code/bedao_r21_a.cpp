#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
bool number_nice_div(int n)
{
	int k = sqrt(n);
	if (k * k != n) return false;

	for (int i = 2; i * i <= k; i++)
	if (k % i == 0)
	{
		if (i <= 200)
		{
			int cur = 1;
			for (int x = 1; x <= 8; x++)
				cur *= i;
			if (cur == n) return true;
		}
		return (prime(i) && prime(k / i));
	}
	return false;	
}

signed main()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;
		cout << (number_nice_div(n)? "YES" : "NO") << '\n';
	}
}