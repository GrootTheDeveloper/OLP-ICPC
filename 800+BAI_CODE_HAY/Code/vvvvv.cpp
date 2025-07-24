#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

bool check(int x)
{
	return x/2 + x/3 + x/5 - x/6 - x/10 - x/15 + x/30 >= n;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int l = 1, r = 1e16;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (check(l - 1)) l--;
	while (!check(l)) l++;
	cout << l;
}
