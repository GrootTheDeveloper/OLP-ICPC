#include <bits/stdc++.h>
using namespace std;

int n, a[800];
namespace sub1
{
	int b[15];
	void work()
	{
		for (int i = 1; i <= n; i++) b[i] = a[i];

		int ans = 0;
		while (next_permutation(b + 1, b + n + 1))
		{
			bool ok = true;
			for (int i = 1; i < n; i++)
				if (b[i] == b[i + 1]) ok = false;
			ans += ok;
			for (int i = 1; i <= n; i++)
				cout << b[i] << ' ';
			cout << '\n';
		}
		bool ok = true;
		for (int i = 1; i < n; i++)
			if (a[i] == a[i + 1]) ok = false;
		cout << ans + ok;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 10) sub1::work();
}
