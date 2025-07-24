#include <bits/stdc++.h>
using namespace std;

int b[3] = {50, 5, 10}, a[9] = {10, 1, 2, 4, 8, 16, 7, 14, 5};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		cout << (n <= 3? b[n - 1] : a[(n - 3) % 9]) << '\n';
	}
}