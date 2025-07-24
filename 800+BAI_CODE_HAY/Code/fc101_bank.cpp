#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[15] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
int calc(int n)
{
	int ans = 0;
	for (int i = 14; i >= 0; i--)
	{
		ans += n / a[i];
		n -= a[i] * (n / a[i]);
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int X; cin >> X;
	int p;
	while (cin >> p)
	{
		int ans = p;
		for (int i = 0; i <= 50000; i++)
		{
			if (i * X > p) break;
			ans = min(ans, i + calc(p - i * X));
		}
		cout << ans << ' ';
	}

}