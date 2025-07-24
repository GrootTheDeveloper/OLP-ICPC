#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int W, L, X; cin >> W >> L >> X;
	int l = 1, r = 1e10;
	int ans = 0; 
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (mid * 100 >= X * (L + mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << max(0ll, ans - W);
}