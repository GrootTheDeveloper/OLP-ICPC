#include <bits/stdc++.h>
using namespace std;
#define int long long 

int sum(int n)
{
	return n * (n + 1) / 2;
}

int calc(int m, int k)
{
	int l = 1, r = 1e9;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (m / k >= sum(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans * k + (m - sum(ans) * k) / (ans + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int m, k; cin >> m >> k;
		cout << calc(m, k) << '\n';
	}

}