#include <bits/stdc++.h>
using namespace std;

int last_num(long long n)
{
	return n % 10;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		int x = last_num(n + 1);
		cout << last_num(x * x) << '\n';
	}
}