#include <bits/stdc++.h>
using namespace std;
#define int long long



int n, q;
int a[200005];
namespace sub1
{

	void solve()
	{
		int ans1 = 0;
		for (int i = 2; i <= n; i++)
			ans1 += abs(a[i] - a[i - 1]);

		int ans2 = -1e15;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (i == 1 && j != n)
				ans2 = max(ans2, ans1 - abs(a[j + 1] - a[j]) - abs(a[j] - a[j - 1]) + abs(a[j + 1] - a[j - 1]) + abs(a[i] - a[j]));
			else if (i != 1 && j == n)
				ans2 = max(ans2, ans1 - abs(a[j] - a[j - 1]) - abs(a[i] - a[i - 1]) + abs(a[i] - a[j]) + abs(a[j] - a[i - 1]));
			else if (i != 1 && j != n)
				ans2 = max(ans2, ans1 - abs(a[j + 1] - a[j]) - abs(a[i] - a[i - 1]) - abs(a[j] - a[j - 1]) + abs(a[j + 1] - a[j - 1]) + abs(a[i] - a[j]) + abs(a[j] - a[i - 1]));
		}
		cout << max({ans1, ans2, ans1 - abs(a[n] - a[n - 1]) + abs(a[1] - a[n])}) << '\n';
	}
	void work()
	{
		while (q--)
		{
			int kind; cin >> kind;
			if (kind == 2) solve();
			else
			{
				int id, x; cin >> id >> x;
				a[id] = x;
			}
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 500 && q <= 500)
		sub1::work();
}