#include <bits/stdc++.h>
using namespace std;


int square_sum(long long n)
{
	int ans = 0;
	while (n) ans += (n % 10) * (n % 10), n /= 10;
	return ans;
}
bool special_num(long long n)
{
	n = square_sum(n);
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)	
		if (n % i == 0) return false;
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	cout << (special_num(n)? 1 : -1) << '\n' << square_sum(n);
}