#include <bits/stdc++.h>
using namespace std;
#define int long long 

int rev(int n)
{
	if (n == 24) return 0;
	int res = ((n < 10) ? n * 10 : n % 10 * 10 + n/10);
	return ((res < 60) ? res : 1000);
}
int out(int a)
{
	if (a == 24) a=0;
	if (a < 10) cout << '0';
	return a;
}
signed main()
{
	string s; cin >> s;
	int a = (s[0] - '0') * 10 + s[1] - '0';
	int b = (s[3] - '0') * 10 + s[4] - '0';
	if (rev(a) == 1000)
	{
		while (rev(a)==1000) a++;
		return cout << out(a) << ':' << out(rev(a)),0;

	}
	if (b < rev(a)) cout << out(a) << ':' << out(rev(a));
	else
	{
		a++;
		while (rev(a)==1000) a++;
		cout << out(a) << ':' << out(rev(a));
	}
}