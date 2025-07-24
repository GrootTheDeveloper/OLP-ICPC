#include <bits/stdc++.h>
using namespace std;

int n, a[1000006], l[1000006], r[1000006];
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void calc_and()
{
	l[1] = a[1];
	r[n] = a[n];
	for (int i = 2; i <= n; i++)
		l[i] = (l[i - 1] & a[i]);
	for (int i = n - 1; i >= 1; i--)
		r[i] = (r[i + 1] & a[i]);
	if (a[1] == r[2] || a[n] == l[n - 1])
		return cout << "Ko ", void();
	for (int i = 2; i < n; i++)
		if ((l[i - 1] & r[i + 1]) == a[i])
			return cout << "Ko ", void();
	cout << "KHoNg ";
}
void calc_xor()
{
	l[1] = a[1];
	r[n] = a[n];
	for (int i = 2; i <= n; i++)
		l[i] = (l[i - 1] ^ a[i]);
	for (int i = n - 1; i >= 1; i--)
		r[i] = (r[i + 1] ^ a[i]);
	if (a[1] == r[2] || a[n] == l[n - 1])
		return cout << "Ko ", void();
	for (int i = 2; i < n; i++)
		if ((l[i - 1] ^ r[i + 1]) == a[i])
			return cout << "Ko ", void();
	cout << "KHoNg ";
}
void calc_or()
{
	l[1] = a[1];
	r[n] = a[n];
	for (int i = 2; i <= n; i++)
		l[i] = (l[i - 1] | a[i]);
	for (int i = n - 1; i >= 1; i--)
		r[i] = (r[i + 1] | a[i]);
	if (a[1] == r[2] || a[n] == l[n - 1])
		return cout << "Ko ", void();
	for (int i = 2; i < n; i++)
		if ((l[i - 1] | r[i + 1]) == a[i])
			return cout << "Ko ", void();
	cout << "KHoNg ";
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	calc_and();
	calc_or();
	calc_xor();
}