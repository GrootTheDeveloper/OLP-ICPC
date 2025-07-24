#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 
int n, sum;

int Calc_odd(int n)
{
	if (n % 2 == 0) n--;
	int cnt = (n - 1) / 2 + 1;
	int s = (n + 1);
	if (cnt % 2 == 0) cnt /= 2;
	else s /= 2;
	return cnt * s;
}
int Calc_even(int n)
{
	if (n&1) n--;
	int cnt = (n - 2) / 2 + 1;
	int s = (2 + n);
	if (cnt % 2 == 0) cnt /= 2;
	else s /= 2;
	return cnt * s;
}

bool check(int mid)
{
	return Calc_odd(mid) >= sum - Calc_even(mid);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int l = 1, r = n;
	sum = Calc_even(n);
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (check(l - 1)) l--;
	while (!check(l)) l++;
	cout << l;
}