#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool check(int n)
{
	int divs = 1, sum = 0;
	while (n)
	{
		divs *= (n % 10);
		sum += n % 10;
		n /	= 10;
	}
	return divs % sum == 0;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) if (check(i)) cout << i << ' ';
}