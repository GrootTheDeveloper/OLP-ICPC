#include <bits/stdc++.h>
using namespace std;
#define int long long 


int sum(int n)
{
	int ans = 0;
	while (n) ans += n%10, n /= 10;
	return ans;
}

bool spen(int n)
{
	int tmp = sum(n);
	int s = 0;
	int x = n;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			s += sum(i);
			n /= i;
		}
	}
	if (n == x) return false;
	if (n != 1) s += sum(n);
	return tmp == s;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	++n;
	while (!spen(n)) n++;
	cout << n;
}

