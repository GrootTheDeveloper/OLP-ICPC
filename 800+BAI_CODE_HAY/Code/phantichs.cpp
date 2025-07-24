#include <bits/stdc++.h>
using namespace std;
#define int long long 


int calc(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
		if (n - i - j > j) res++;
	return res;
}

void init(int n)
{
	int lim = n / 3;
	int res = 0;
	for (int i = 1; i <= lim; i++)
	{
		int x = (n - i) >> 1;
		if (x * 2 == n - i) x--;
		if (x > i) res += x - i;
	}
	cout << res;
}

signed main()
{
	//int n; cin >> n;
	//if (n <= 5000) cout << calc(n);
	//cout << calc(n) << '\n';
	init(500000000);
	cout << clock() / (double)1000 << " sec";
}