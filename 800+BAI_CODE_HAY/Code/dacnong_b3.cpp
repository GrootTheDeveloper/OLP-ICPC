#include <bits/stdc++.h>
using namespace std;

bool prime[200];
void sie_prime()
{
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < 200; i++)
	if (!prime[i]) for (int j = i * i; j < 200; j += i)
		prime[j] = true;
}

namespace sub1
{
	int sum_digit(int n)
	{
		int ans = 0;
		while (n) ans += n % 10, n /= 10;
		return ans;
	}
	bool is_Palindrome_number(int n)
	{
		int tmp = n;
		int newN = 0;
		while (tmp) 
		{
			newN = newN * 10 + tmp % 10;
			tmp /= 10;
		}
		return (newN == n && !prime[sum_digit(n)]);
	}
	void work(int l, int r)
	{
		int ans = 0;
		for (int i = l; i <= r; i++)
			ans += is_Palindrome_number(i);
		cout << ans << ' ';
	}
}

namespace sub2
{

	int pow10[8];

	long long dup_odd_number(int n)
	{
		if (n < 10) return n;
		int tmp = n / 10;
		int add = 0, cnt = 0;
		while (tmp) add = add * 10 + tmp % 10, tmp /= 10, ++cnt;
		return 1ll * n * pow10[cnt] + add;
	}
	long long dup_even_number(int n)
	{
		int tmp = n;
		int add = 0, cnt = 0;
		while (tmp) add = add * 10 + tmp % 10, tmp /= 10, ++cnt;
		return 1ll * n * pow10[cnt] + add;
	}
	int sum_digit(long long n)
	{
		int ans = 0;
		while (n) ans += n % 10, n /= 10;
		return ans;
	}
	void work(int l, int r)
	{
		int ans = 0;
		pow10[0] = 1;
		for (int i = 1; i <= 7; i++)
			pow10[i] = pow10[i - 1] * 10;
		for (int i = 1; i <= 1e6; i++)
		{
			long long num1 = dup_odd_number(i), num2 = dup_even_number(i);
			if (num1 >= l && num1 <= r)
				ans += (!prime[sum_digit(num1)]);
			if (num2 >= l && num2 <= r)
				ans += (!prime[sum_digit(num2)]);
		}
		cout << ans;

	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, r; cin >> l >> r;
	sie_prime();
	if (r <= 1e6) sub1::work(l, r);
	else sub2::work(l, r);

}