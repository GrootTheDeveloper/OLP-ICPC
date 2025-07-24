#include <bits/stdc++.h>
using namespace std;

int Pow(int a, int b)
{
	int ans = 1;
	for (int i = 1; i <= b; i++)
		ans *= a;
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	while (n--)
	{
		int ai; cin >> ai;
		int k = ai % 10;
		ai /= 10;
		ans += Pow(ai, k);
	}
	cout << ans;
}